
#ifndef _AF_Q_SCALER_H
#define _AF_Q_SCALER_H

/* AfScaler
	图像适应外框，保持长宽比放缩

	作者：邵发
	版本: 2015-12-29
	官网: http://afanihao.cn 
*/
#include <QRect>

class AfScaler
{

public:
	// source: 图像实际大小
	// target: 目标矩形
	static QRect scale(QRect source, QRect target)
	{
		int target_w = target.width();
		int target_h = target.height();

		int image_w = source.width();
		int image_h = source.height();

		if(image_w <= 0) image_w = 1;
		if(image_h <= 0) image_h = 1;

		int scaled_w = target_w;
		int scaled_h = image_h * target_w / image_w;
		if(scaled_h > target_h)
		{
			scaled_h = target_h;
			scaled_w = target_h * image_w / image_h;
		}

		// 坐在中心
		int off_x = (target_w - scaled_w)/2;
		int off_y = (target_h - scaled_h)/2;
		return QRect(target.left() + off_x,  target.top()+ off_y, scaled_w, scaled_h);
	}


};





#endif

