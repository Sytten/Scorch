#ifndef BEZIERCURVES_H
#define BEZIERCURVES_H

#include <iostream>
#include <math.h>
#include <time.h>

#include<QVector>
#include<QPointF>

enum BezierMode{
	Flat = 0,
	LowCurves,
	HighCurves,
	InsaneCurves
};

class Curves
{
public:
	Curves(BezierMode p_mode = BezierMode::LowCurves, float basePointsSpacing = 10, float curveEndPoints = 1920);
	~Curves();

	// setter.
	void setBezierMode(BezierMode p_mode);

	QVector<QPointF> getPoints() const;
	QVector<QPointF> getBasePoint() const;
	float getPt(float n1, float n2, float perc);


private:
	BezierMode m_mode;

	QVector<QPointF>  m_points;
	QVector<QPointF>  m_basePoints;

	float m_spacing, m_end;

	void createBezierBasePoints();
	void createBezierCurvesPoints();
};

#endif