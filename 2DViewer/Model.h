#pragma once
#include "IModel.h"
class Model : public IModel 
{	
	virtual void setController(IControllerInView* pController);
	virtual void addNewFiguretoBase(IFigure* f);
	virtual void updateView();
	virtual void deleteSelected();
	virtual void updateSelected();
	virtual void selectToDownInBase();
	virtual void setDXDYToSelected();	
	virtual bool setActiveBorderToInWork();
	virtual void setActiveToSelected();
	virtual bool setActiveToInWork();
	inline virtual void mainDo() {workStrategyBase->mainDo();};
	inline virtual void mainEnd() {workStrategyBase->mainEnd();};	
	inline virtual POINT& getPoint() { return point_; };
	
	inline virtual void updateMousePlace(UINT NFlags, CPoint point)
	{
		nFlags_ = NFlags;
		point_ = point;	
		notifyView();
	};

	inline virtual void setWorkStrategyBase()
	{
		workStrategyBase = 
			std::make_shared<WorkStrategyBase>(this);
	}

	inline virtual void setWorkStrategyNew()
	{
		workStrategyBase = 
			std::make_shared<WorkStrategyNew>(this);
	}

	inline virtual void setWorkStrategyMoveSelected()
	{
		workStrategyBase = 
			std::make_shared<WorkStrategyMoveSelected>(this);
	}

	inline virtual void setWorkStrategyChangeBorder()
	{
		workStrategyBase = 
			std::make_shared<WorkStrategyChangeBorder>(this);
		this->inWork.oldPoint = getPoint();
	}

	virtual void setWorkStrategyMoveOne()
	{
		workStrategyBase = std::make_shared<WorkStrategyMoveOne>(this);
		this->inWork.oldPoint = getPoint();
	}

	virtual ~Model() = default;
	//{ //delete controller_;}

private:
	#define STRUCTWORKSTRATEGY(N) struct N :public \
	WorkStrategyBase {N(Model * m) :WorkStrategyBase(m) {}; \
	virtual ~N() {TRACE("Dest "#N"\n"); };
	
	struct WorkStrategyBase
	{
		Model* m; 
		WorkStrategyBase(Model* _m) { m = _m; }
		virtual void mainDo(const CPoint& point) {};
		virtual void mainDo() { mainDo(m->getPoint()); }
		virtual void mainEnd() { }
		virtual ~WorkStrategyBase() { TRACE("Destroy WorkStrategyBase\n"); };
	};

	STRUCTWORKSTRATEGY(WorkStrategyNew)
		virtual void mainDo(const CPoint& point);
		virtual void mainEnd() { m->inWork.it->unSelected(); }
	};

	STRUCTWORKSTRATEGY(WorkStrategyMoveSelected)
		virtual void mainDo(const CPoint& point);	
	};

	STRUCTWORKSTRATEGY(WorkStrategyChangeBorder)
		virtual void mainDo(const CPoint& point);
	};

	STRUCTWORKSTRATEGY(WorkStrategyMoveOne)
		virtual void mainDo(const CPoint& point);
	};		
	#undef STRUCTWORKSTRATEGY

	//class WorkStrategyBase;
	IFigure::FigureInChanged inWork;
	std::vector<IFigure*> data_;
	UINT nFlags_;
	POINT point_;
	IControllerInView* controller_;
	// = std::shared_ptr<IControllerInView>(nullptr);
	std::shared_ptr<WorkStrategyBase> workStrategyBase = 
		std::make_shared<WorkStrategyBase>(this);
}; 


//1415095/doevents

