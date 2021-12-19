/*
 Copyright (c) 2021 Haobin Chen

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <backend/assembly.hh>
#include <common/compile_excepts.hh>
#include <common/utils.hh>

compiler::reg::Machine_operand::Machine_operand(const operand_type& type,
                                                const std::string& val)
    : type(type), label("") {
  if (type == IMM) {
    this->val = val;
  } else {
    register_name = val;
  }
}

compiler::reg::Machine_operand::Machine_operand(const std::string& label)
    : type(LABEL), val(""), label(label) {}

compiler::reg::Machine_operand::Machine_operand(const Machine_operand& operand)
    : type(operand.type),
      val(operand.val),
      label(operand.label),
      register_name(operand.register_name),
      parent(operand.parent) {}

void compiler::reg::Machine_operand::set_register_name(
    const std::string& name) {
  // Note that this function can be called only after a physical register is
  // available for this operand! Otherwise do not invoke this function to set
  // the register name because this may alter the property of the operand.
  register_name = name;
  type = compiler::reg::operand_type::REG;
}

bool compiler::reg::Machine_operand::operator==(
    const Machine_operand& rhs) const {
  // Different types cannot be compared!
  if (type != rhs.type) {
    return false;
  }
  if (type == IMM) {
    return val == rhs.val;
  }
  return register_name == rhs.register_name;
}

bool compiler::reg::Machine_operand::operator<(
    const Machine_operand& rhs) const {
  return true;
  // Note that std::string has already overridden comparison operators.
  if (type == rhs.type) {
    if (type == IMM) {
      return val < rhs.val;
    }
    return register_name < rhs.register_name;
  }

  return type < rhs.type;

  if (type != rhs.type) {
    return false;
  }
  if (type == IMM) {
    return val == rhs.val;
  }
  return register_name == rhs.register_name;
}

std::string compiler::reg::Machine_operand::print(void) const {
  std::ostringstream oss;
  switch (type) {
    case IMM: {
      oss << "#" << val;
      break;
    }
    case REG:
    case VREG: {
      oss << register_name;
      break;
    }
    case LABEL: {
      oss << label;
      // if (label.substr(0, 3).compare(".LB") == 0) {
      //   oss << label;
      // } else {
      //   oss << "addr_" << label;
      // }
      break;
    }
  }
  return oss.str();
}

compiler::reg::Machine_instruction_binary::Machine_instruction_binary(
    Machine_block* const parent, const compiler::reg::binary_type& op,
    Machine_operand* const dst, Machine_operand* const operand_a,
    Machine_operand* const operand_b, const cond_type& cond) {
  this->parent = parent;
  this->type = BINARY;
  this->cond = cond;
  this->op = op;

  def_list.emplace_back(dst);
  use_list.emplace_back(operand_a);
  use_list.emplace_back(operand_b);
  dst->set_parent(this);
  operand_a->set_parent(this);
  operand_b->set_parent(this);
}

compiler::reg::Machine_instruction_branch::Machine_instruction_branch(
    Machine_block* const parent, const branch_type& op,
    Machine_operand* const label, const cond_type& cond) {
  this->parent = parent;
  this->op = op;
  this->cond = cond;
  use_list.emplace_back(label);
  label->set_parent(this);
}

compiler::reg::Machine_instruction_alloca::Machine_instruction_alloca(
    Machine_block* const parent, Machine_operand* const var,
    const cond_type& cond) {
  this->parent = parent;
  def_list.emplace_back(var);
  var->set_parent(this);
}

compiler::reg::Machine_instruction_load::Machine_instruction_load(
    Machine_block* const parent, Machine_operand* const dst,
    Machine_operand* const operand_a, Machine_operand* const operand_b,
    const cond_type& cond) {
  this->parent = parent;
  this->type = LOAD;
  this->cond = cond;
  this->imm_trans = true;

  def_list.emplace_back(dst);
  use_list.emplace_back(operand_a);

  if (operand_b != nullptr) {
    use_list.emplace_back(operand_b);
    operand_b->set_parent(this);
  }
  dst->set_parent(this);
  operand_a->set_parent(this);
}

compiler::reg::Machine_instruction_mov::Machine_instruction_mov(
    Machine_block* const parent, const compiler::reg::mov_type& op,
    Machine_operand* const dst, Machine_operand* const src,
    const cond_type& cond) {
  this->parent = parent;
  this->op = op;
  this->cond = cond;
  def_list.emplace_back(dst);
  use_list.emplace_back(src);
  dst->set_parent(this);
  src->set_parent(this);
}

compiler::reg::Machine_instruction_stack::Machine_instruction_stack(
    Machine_block* const parent, const stack_type& op,
    Machine_operand* const src, const cond_type& cond) {
  this->parent = parent;
  this->op = op;
  this->cond = cond;

  use_list.emplace_back(src);
  src->set_parent(this);
}

// -> STR r0, [r1, <r2>] where r2 is optional.
compiler::reg::Machine_instruction_store::Machine_instruction_store(
    Machine_block* const parent, Machine_operand* const operand_a,
    Machine_operand* const operand_b, Machine_operand* const operand_c,
    const cond_type& cond) {
  this->parent = parent;
  this->type = BINARY;
  this->cond = cond;
  this->imm_trans = true;

  use_list.emplace_back(operand_a);
  use_list.emplace_back(operand_b);
  operand_a->set_parent(this);
  operand_b->set_parent(this);
  if (operand_c != nullptr) {
    use_list.emplace_back(operand_c);
    operand_c->set_parent(this);
  }
}

compiler::reg::Machine_instruction_cmp::Machine_instruction_cmp(
    Machine_block* const parent, Machine_operand* const operand_a,
    Machine_operand* const operand_b, const cond_type& cond) {
  this->parent = parent;
  use_list.emplace_back(operand_a);
  use_list.emplace_back(operand_b);
  operand_a->set_parent(this);
  operand_b->set_parent(this);
}

void compiler::reg::Machine_instruction_load::emit_assembly(
    std::ostream& os) const {
  os << "\tldr ";
  os << def_list[0]->print() << ", ";

  // Load from immediate value.
  // E.g.: ldr r8, =8
  if (use_list[0]->is_imm()) {
    os << "=" << use_list[0]->get_value() << '\n';
    return;
  }

  // Load from address summed up by the registers.
  // E.g.: ldr r0, [r1, <r2>].
  if (use_list[0]->is_reg() || use_list[0]->is_vreg()) {
    os << "[" << use_list[0]->print();

    if (use_list.size() > 1) {
      os << ", " << use_list[1]->print();
    }

    os << "]" << '\n';
  }
}

void compiler::reg::Machine_instruction_binary::emit_assembly(
    std::ostream& os) const {
  switch (op) {
    case ADD:
      os << compiler::generate_assembly("\tadd", def_list[0]->print(),
                                        use_list[0]->print(),
                                        use_list[1]->print())
         << '\n';
      break;
    case SUB:
      os << compiler::generate_assembly("\tsub", def_list[0]->print(),
                                        use_list[0]->print(),
                                        use_list[1]->print())
         << '\n';
      break;
    case MUL:
      os << compiler::generate_assembly("\tmul", def_list[0]->print(),
                                        use_list[0]->print(),
                                        use_list[1]->print())
         << '\n';
      break;
    case DIV:
      os << compiler::generate_assembly("\tsdiv", def_list[0]->print(),
                                        use_list[0]->print(),
                                        use_list[1]->print())
         << '\n';
      break;
    case BAND:
      os << compiler::generate_assembly("\tand", def_list[0]->print(),
                                        use_list[0]->print(),
                                        use_list[1]->print())
         << '\n';
      break;
    case BOR:
      os << compiler::generate_assembly("\tor", def_list[0]->print(),
                                        use_list[0]->print(),
                                        use_list[1]->print())
         << '\n';
      break;
    case BXOR:
      os << compiler::generate_assembly("\txor", def_list[0]->print(),
                                        use_list[0]->print(),
                                        use_list[1]->print())
         << '\n';
      break;

    case MOD:
      handle_modulus(os);
      break;
    default:
      throw compiler::unsupported_operation(
          "Error: This binary operation is not supported!");
  }
}

void compiler::reg::Machine_instruction_binary::handle_modulus(
    std::ostream& os) const {
  // mov r0, op1
  // mov r1, op2
  // bl __aeabi_idivmod
}

void compiler::reg::Machine_instruction_store::emit_assembly(
    std::ostream& os) const {
  // There shouldn't be something like
  // STR #8, [r0] ?
  os << "\tstr ";
  os << use_list[0]->print() << ", [";
  os << use_list[1]->print();
  if (use_list.size() > 2) {
    os << ", " << use_list[2]->print();
  }
  os << "]" << '\n';
}

void compiler::reg::Machine_instruction_mov::emit_assembly(
    std::ostream& os) const {
  if (op != MOV_N) {
    os << "\tmov " << def_list[0]->print() << ", #0\n";
  }

  switch (op) {
    case MOV_N: {
      // Check if the immediate is too large...
      if (use_list[0]->print()[0] == '#' &&
          std::stoi(use_list[0]->print().substr(1)) > maximum_immediate) {
        os << "\tldr " << def_list[0]->print() << ", =" << use_list[0]->print()
           << '\n';
        return;
      }
      os << "\tmov ";
      break;
    }
    case MOVEQ: {
      os << "\tmoveq ";
      break;
    }
    case MOVNE: {
      os << "\tmovne ";
      break;
    }
    case MOVGT: {
      os << "\tmovgt ";
      break;
    }
    case MOVGE: {
      os << "\tmovge ";
      break;
    }
    case MOVLT: {
      os << "\tmovlt ";
      break;
    }
    case MOVLE: {
      os << "\tmovle ";
      break;
    }
    case MOV32: {
      os << "\tmov32 ";
      break;
    }
  }
  os << def_list[0]->print() << ", " << use_list[0]->print() << '\n';
}

void compiler::reg::Machine_instruction_branch::emit_assembly(
    std::ostream& os) const {
  switch (op) {
    case BL: {
      os << "\tbl ";
      break;
    }
    case BX: {
      os << "\tbx ";
      break;
    }
    case B: {
      os << "\tb ";
      break;
    }
    case BLT: {
      os << "\tblt ";
      break;
    }
    case BGE: {
      os << "\tbge ";
      break;
    }
    case BLE: {
      os << "\tble ";
      break;
    }
    case BGT: {
      os << "\tbgt ";
      break;
    }
    case BNE: {
      os << "\tbne ";
      break;
    }
    case BEQ: {
      os << "\tbeq ";
      break;
    }
  }
  os << use_list.front()->print() << '\n';
}

void compiler::reg::Machine_instruction_stack::emit_assembly(
    std::ostream& os) const {
  // Caveat: We do not support scalar push / pop operations.
  // E.g.: push {r0, r1} is not supported.
  if (op == PUSH) {
    os << "\tpush {" << use_list[0]->print() << "}\n";
  } else {
    os << "\tpop {" << use_list[0]->print() << "}\n";
  }
}

void compiler::reg::Machine_instruction_cmp::emit_assembly(
    std::ostream& os) const {
  os << "\tcmp " << use_list[0]->print() << ", " << use_list[1]->print()
     << '\n';
}