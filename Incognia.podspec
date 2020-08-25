Pod::Spec.new do |s|
    s.name             = 'Incognia'
    s.version          = '5.4.0'
    s.summary          = 'Incognia - Incognia SDK' 
    s.description      = <<-DESC
                     Incognia offers the first private identity solution based on location behavior for frictionless authentication and identity verification.
                     DESC
    s.homepage         = 'https://www.incognia.com/'
    s.license          = 'Copyright'
    s.author           = { "Incognia" => "contact@incognia.com" }
    s.source           = { :git => "https://github.com/incognia-org/incognia-sdk-pods.git", :tag => "5.4.0" }
    s.documentation_url = "https://docs.incognia.com/"
    s.ios.deployment_target = '9.0'
    s.xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
    s.license = 'LICENSE' 
    s.frameworks = 'Foundation'
    s.vendored_frameworks = 'IncogniaSDK/Incognia.framework'
    s.requires_arc = true
    s.dependency 'IncogniaCore', '5.4.0'
  end