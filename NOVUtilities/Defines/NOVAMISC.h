//
//  NOVAMISC.h
//  Pods
//
//  Created by John Shu on 2019/12/3.
//

#ifndef NOVAMISC_h
#define NOVAMISC_h


#define LOC(title) NSLocalizedString(title, title)

// 拿到storyboard中的vc
#define STBDBundleVC(bundleName, vcName) [[UIStoryboard storyboardWithName:bundleName bundle:nil] instantiateViewControllerWithIdentifier:vcName]
#define STBDVC(vcName) STBDBundleVC(@"Main", vcName)

// 拿到xib中的vc
#define XIBVC(_class) [[_class alloc] initWithNibName:NSStringFromClass([_class class]) bundle:nil]

// 拿到xib中的view
#define XIBBundleView(bundle, xibName, _owner) [[bundle loadNibNamed:xibName owner:_owner options:nil] firstObject]
#define XIBView(xibName, _owner) XIBBundleView([NSBundle mainBundle], xibName, _owner)

// 用在cell的注册中
#define NIB(nibName) [UINib nibWithNibName:nibName bundle:nil]

#define AttrStr(_str_, _font_, _color_) [[NSAttributedString alloc] initWithString:_str_ attributes:@{NSForegroundColorAttributeName: _color_, NSFontAttributeName: _font_}]
#define URLFromStr(_str_) [NSURL URLWithString:_str_]

#endif /* NOVAMISC_h */
