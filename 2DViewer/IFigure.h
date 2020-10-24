#pragma once
#include "IControllerInView.h"
#include <wtypes.h>
#include <functional>
#include "IControllerInView.h"
#include <memory>
template<typename T> using TDataFromView = std::function<void(T&)>;

#define PROPERTY(NAME) private:\
	bool NAME##_ = false; \
 public:\
 bool is##NAME(){ return NAME##_; }; \
 void to##NAME(){ NAME##_ = true; }; \
 void un##NAME(){ NAME##_ = false; };

//doxygen comments sample

struct IFigure
{
	//the thickness of the border
	static constexpr int THB = 3;
	struct FigureInChanged
	{
		IFigure* it;
		CPoint oldPoint;
		CPoint newPoint;
	};

	/*!
	\brief Init figure.

	Set Data to figure and set select state
	\param point Figure coordinates
   */
	inline void init(CPoint point)
	{
		point_ = point;
		toSelected();
	};

	/*!
	\brief set Figure place.

	Set new place coordinates
	\param point Figure coordinates
   */
	inline void setPlace(int x, int y)
	{
		point_.x = x; point_.y = y;
	};

	/*!
	Set delta between mouse place and figure place.
	\param point mouse coordinates
	 */
	inline void setDeltaPoint(const CPoint& point)
	{
		dPoint_.x = point.x - point_.x;
		dPoint_.y = point.y - point_.y;
	};

	/*!
	Get data. By pull from view.
	 */
	virtual void getData() = 0;

	/*!
	Check mouse in Figure inside
	\param point mouse coordinates
	*/
	virtual bool checkInside(const CPoint& point) = 0;

	/*!
	Out figure to view
	\param outHelper Helper for out figure
	*/
	virtual void outToView(IControllerInView* outHelper) = 0;

	/*!
	Check mouse in Figure bordes
	\param point mouse coordinates
	*/
	virtual bool isInBorder(const CPoint& point) = 0;

	/*!
	Change figure by old and new place inside border
	\param oldPoint old coordinates inside border
	\param newPoint new coordinates inside border
	*/
	virtual void setDataBorder(CPoint oldPoint, CPoint newPoint) = 0;
	//todo replace to property
	CPoint dPoint_{ 0,0 };
	CPoint point_;
	PROPERTY(Selected)

	virtual ~IFigure() = default;
};

