Pod::Spec.new do |s|
  s.name         = "BRLMPrinterKit"
  s.version      = "4.3.1"
  s.summary      = "Brother Print SDK for iPhone/iPad"
  s.description  = "For sample projects and more detailed product page, check out: http://www.brother.com/product/dev/mobile/ios/"
  s.homepage     = "http://www.brother.com/product/dev/mobile/ios/"
  s.license      = { :type => "CUSTOM" }
  s.author       = "Brother Industries, Ltd."
  s.platform     = :ios, "9.0"
  s.source       = { :git => "https://github.com/lipka/BRLMPrinterKit.git", :tag => s.version }
  s.ios.vendored_frameworks = 'Frameworks/BRLMPrinterKit.xcframework'
  s.frameworks = "SystemConfiguration", "UIKit", "CoreBluetooth", "ExternalAccessory", "BRLMPrinterKit"
  s.library   = "c++", "z"
end
