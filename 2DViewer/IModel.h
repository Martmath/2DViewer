#pragma once
#include "IFigure.h"
#include <vector>

struct IModel
{
	///<summary>Set from Observer. Notify observer after change mouse place</summary>
	std::function<void(void)> notifyView;

	///<summary>Initializing an internal pointer to Controller</summary>
	virtual void setController(IControllerInView* pController) = 0;

	///<summary>Add new figure to list.</summary>
	///<param name="pFigure">Figure for add</param>
	virtual void addNewFiguretoBase(IFigure* pFigure) = 0;

	///<summary>Update Viewer</summary>
	virtual void updateView() = 0;

	///<summary>Delete selected figure</summary>
	virtual void deleteSelected() = 0;

	///<summary>Update mouse data of selected figure</summary>
	virtual void updateSelected() = 0;

	///<summary>Set move selected figure action for work</summary>
	virtual void selectToDownInBase() = 0;

	///<summary>Set delta between mouse place and selected figures place</summary>
	virtual void setDXDYToSelected() = 0;

	///<summary>Set object under mouse to InWork</summary>
	///<returns>found or not object under mouse</returns>
	virtual bool setActiveBorderToInWork() = 0;

	///<summary>Select object under mouse</summary>
	virtual void setActiveToSelected() = 0;

	///<summary>Set element for action with single figure</summary>
	virtual bool setActiveToInWork() = 0;

	///<summary>Main action. Called from view cicle</summary>
	virtual void mainDo() = 0;

	///<summary>Called from view cicle</summary>
	virtual void mainEnd() = 0;

	///<summary>Update mouse Model data as Observer. Must be called from View.</summary>
	///<returns>Found or not object under mouse</returns>
	virtual const POINT& getPoint() = 0;

	///<summary>Update mouse Model data as Observer. Must be called from View.</summary>
	///<param name="nFlags">Current mouse flag</param>
	///<param name="point">Current mouse place</param>
	virtual void updateMousePlace(UINT nFlags, CPoint point) = 0;

	///<summary>Set Zero action for work</summary>
	virtual void setWorkStrategyBase() = 0;

	///<summary>Set Add figure action for work</summary>
	virtual void setWorkStrategyNew() = 0;

	///<summary>Set move selected figure action for work</summary>
	virtual void setWorkStrategyMoveSelected() = 0;

	///<summary>Set change border figure action for work</summary>
	virtual void setWorkStrategyChangeBorder() = 0;

	///<summary>Set move with shift figure under mouse action for work</summary>
	virtual void setWorkStrategyMoveOne() = 0;

	virtual ~IModel() = default;
};







