Pod::Spec.new do |s|
  s.name             = 'ZSOpenCore'
  s.version          = '1.0.4'
  s.summary          = 'Open SDK for qkagame'
  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/zhongshungame/ZSOpenCore'
  s.license          = { :type => 'MIT'}
  s.author           = { 'zhongshungame' => 'xiuxianyx20@163.com' }
  s.source           = { :git => 'https://github.com/zhongshungame/ZSOpenCore.git', :tag => s.version.to_s }

  s.ios.deployment_target = '8.0'

  s.vendored_frameworks = 'Frameworks/ZSOpenCore.framework'
  s.frameworks   = 'UIKit','Foundation'
  
  s.user_target_xcconfig = { 'OTHER_LDFLAGS' => '-ObjC','ENABLE_STRICT_OBJC_MSGSEND'=>'NO' }

  s.dependency 'AFNetworking','3.2.1'
  s.dependency 'MJExtension'

end
