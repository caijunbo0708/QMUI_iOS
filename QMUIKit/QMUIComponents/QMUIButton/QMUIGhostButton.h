//
//  QMUIGhostButton.h
//  QMUIKit
//
//  Created by MoLice on 2018/4/9.
//  Copyright © 2018年 QMUI Team. All rights reserved.
//

#import "QMUIButton.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, QMUIGhostButtonColor) {
    QMUIGhostButtonColorBlue,
    QMUIGhostButtonColorRed,
    QMUIGhostButtonColorGreen,
    QMUIGhostButtonColorGray,
    QMUIGhostButtonColorWhite,
};

/**
 *  用于 `QMUIGhostButton.cornerRadius` 属性，当 `cornerRadius` 为 `QMUIGhostButtonCornerRadiusAdjustsBounds` 时，`QMUIGhostButton` 会在高度变化时自动调整 `cornerRadius`，使其始终保持为高度的 1/2。
 */
extern const CGFloat QMUIGhostButtonCornerRadiusAdjustsBounds;

/**
 *  “幽灵”按钮，也即背景透明、带圆角边框的按钮
 *
 *  可通过 `QMUIGhostButtonColor` 设置几种预设的颜色，也可以用 `ghostColor` 设置自定义颜色。
 *
 *  @warning 默认情况下，`ghostColor` 只会修改文字和边框的颜色，如果需要让 image 也跟随 `ghostColor` 的颜色，则可将 `adjustsImageWithGhostColor` 设为 `YES`
 */
@interface QMUIGhostButton : QMUIButton

@property(nonatomic, strong, nullable) IBInspectable UIColor *ghostColor;    // 默认为 GhostButtonColorBlue
@property(nonatomic, assign) CGFloat borderWidth UI_APPEARANCE_SELECTOR;    // 默认为 1pt
@property(nonatomic, assign) CGFloat cornerRadius UI_APPEARANCE_SELECTOR;   // 默认为 QMUIGhostButtonCornerRadiusAdjustsBounds，也即固定保持按钮高度的一半。

/**
 *  控制按钮里面的图片是否也要跟随 `ghostColor` 一起变化，默认为 `NO`
 */
@property(nonatomic, assign) BOOL adjustsImageWithGhostColor UI_APPEARANCE_SELECTOR;

- (instancetype)initWithGhostType:(QMUIGhostButtonColor)ghostType;
- (instancetype)initWithGhostColor:(nullable UIColor *)ghostColor;

@end

NS_ASSUME_NONNULL_END
