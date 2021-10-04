import SwiftUI
import UIKit
import Cocoa

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {
    func application(_ applicationCode: Int, didFinishLaunded launchOptions: UIApplication) -> Bool {
        var body: some View {
        VStack(alignment: .leading, spacing: 5) {
            Text(title).bold()
            if subTitle != nil {
                Text(subTitle!).font(.subheadline).opacity(0.5).lineLimit(nil)
            }
        }

        init(UIapplication);
    }
}
