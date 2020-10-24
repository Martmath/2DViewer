#include "pch.h"
#include "Model.h"

void Model::setController(IControllerInView* pController)
{
	controller_ = pController;
}

void Model::addNewFiguretoBase(IFigure* f)
{
	data_.push_back(f); 
	inWork.it = f;
}

void Model::selectToDownInBase()
{
	std::vector<IFigure*>dataTemp;
	/*for (size_t i = 0; i < data_.size(); i++) { if (data_[i]->isSelected()) 
	{ dataTemp.push_back(data_[i]); data_.erase(data_.begin() + i); i--; } }
	for (size_t i = 0; i < dataTemp.size(); i++) { data_.push_back(dataTemp[i]); }*/
	for (size_t i = 0; i < data_.size(); i++) 
	{ 
		if (!data_[i]->isSelected()) 
			dataTemp.push_back(data_[i]); 

	}
	for (size_t i = 0; i < data_.size(); i++) 
	{ 
		if (data_[i]->isSelected())
			dataTemp.push_back(data_[i]);
	}
	data_.clear();
	data_ = dataTemp;
}

void Model::deleteSelected()
{
	std::vector<IFigure*> dataTmp;
	dataTmp.reserve(data_.size());
	for (auto& e : data_)
	{
		if (!e->isSelected()) dataTmp.push_back(e); else delete e;
	}
	data_.clear();
	data_ = dataTmp;
	/*for (size_t i = 0; i < data_.size(); i++) {//медленно
	if (data_[i]->isSelected()) { delete data_[i]; 
	data_.erase(data_.begin() + i); i--; }
	}*/
}

void Model::updateSelected()
{
	for (auto& e : data_) 
	{ 
		if (e->isSelected()) e->getData(); 
	}
}

void Model::setDXDYToSelected()
{
	for (auto& e : data_)
	{
		if (e->isSelected()) e->setDeltaPoint(getPoint());
	}
}

bool Model::setActiveToInWork()
{
	for (auto e = data_.rbegin(); e != data_.rend(); ++e)
	{
		if ((*e)->checkInside(getPoint()))
		{
			inWork.it = (*e);
			(*e)->setDeltaPoint(getPoint());
			return true;
		}
	}
	return false;
}

bool Model::setActiveBorderToInWork() {
	for (auto& e : data_)
	{
		if (e->isInBorder(getPoint()))
		{
			inWork.it = e; 
			return true;
		}
	}
	return false;
}

void Model::setActiveToSelected()
{
	for (auto e = data_.rbegin(); e != data_.rend(); ++e)
	{
		if ((*e)->checkInside(getPoint()))
		{
			if (!(*e)->isSelected())
			{ 
				(*e)->toSelected(); 
				(*e)->setDeltaPoint(getPoint()); 
			}
			else 		
				(*e)->unSelected(); 
			return;
		}
	}
}

void Model::updateView() 
{ 
	for (auto& e : data_) 
		e->outToView(controller_); 
}

void Model::WorkStrategyNew::mainDo(const CPoint& point)
{
	auto& it = m->inWork.it;
	it->setPlace(point.x - it->dPoint_.x, point.y - it->dPoint_.y);
	it->outToView(m->controller_);
}

void Model::WorkStrategyMoveSelected::mainDo(const CPoint& point)
{
	for (auto& e : m->data_)
	{
		if (e->isSelected())
		{
			e->setPlace(point.x - e->dPoint_.x, point.y - e->dPoint_.y);
			e->outToView(m->controller_);
		}
	}
}

void Model::WorkStrategyChangeBorder::mainDo(const CPoint& point)
{
	auto& inWork = m->inWork;
	inWork.newPoint = point;  
	inWork.it->setDataBorder(inWork.oldPoint, inWork.newPoint);
	inWork.oldPoint = inWork.newPoint;
	inWork.it->outToView(m->controller_);
}

void Model::WorkStrategyMoveOne::mainDo(const CPoint& point)
{
	auto& it = m->inWork.it;
	it->setPlace(point.x - it->dPoint_.x, point.y - it->dPoint_.y);
}