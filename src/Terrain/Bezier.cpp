#include "Terrain/Bezier.h"

using namespace std;

Curves::Curves(BezierMode p_mode, float p_basePointsSpacing, float p_curveEndPoints)
{
	srand(time(0));
	m_mode = p_mode;
	m_spacing = p_basePointsSpacing;
	m_end = p_curveEndPoints;
	createBezierBasePoints();
	createBezierCurvesPoints();

	//for (int i = 0; i < m_points.length(); i++)
		//cout << " Point : " << i << "; " << m_points[i].rx() << "," << m_points[i].ry() << endl;
}

Curves::~Curves()
{}

void Curves::setBezierMode(BezierMode p_mode)
{
	m_mode = p_mode;
}


float Curves::getPt(float n1, float n2, float perc)
{
	float diff = n2 - n1;

	return n1 + diff*perc;
}


QVector<QPointF> Curves::getPoints() const
{
	return m_points;
}


void Curves::createBezierBasePoints()
{
	if (m_mode == BezierMode::InsaneCurves)	{
		for (int i = 0; i < m_end; i += m_spacing){
			m_basePoints += QPointF(i, (rand() % 100) + (fmod(rand(), 1000) / 1000));
		}
	}
	else if (m_mode == BezierMode::Flat){
		for (int i = 0; i < m_end; i += m_spacing){
			m_basePoints += QPointF(i, 1.0f);
		}
	}
	else if (m_mode == BezierMode::HighCurves){
		for (int i = 0; i < m_end; i += m_spacing){
			m_basePoints += QPointF(i, (rand() % 100) + (fmod(rand(), 100) / 1000));
		}
	}
	else{
		for (int i = 0; i < m_end; i += m_spacing){
			m_basePoints += QPointF(i, (rand() % 10) + (fmod(rand(), 100) / 1000));
		}
	}

}

void Curves::createBezierCurvesPoints()
{
	float xa = -1;
	float xb = -1;
	float ya = -1;
	float yb = -1;

	for (int i = 0; i < m_basePoints.length() - 2; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			/*xa = getPt(m_basePoints[i].rx(), m_basePoints[i + 1].rx(), j * 0.1);
			ya = getPt(m_basePoints[i].ry(), m_basePoints[i + 1].ry(), j * -0.1);

			xb = getPt(m_basePoints[i + 1].rx(), m_basePoints[i + 2].rx(), j * 0.1);
			yb = getPt(m_basePoints[i + 1].ry(), m_basePoints[i + 2].ry(), j * -0.1);

			m_points += QPointF(((1 - j * 0.01) * xa) + (j * 0.01 * xb), ((1 - j * 0.01) * ya) + (j * 0.01 * yb));*/
			//m_points += QPointF(getPt(xa, xb, 0.1), getPt(ya, yb, 0.1));
		}
	}
}


QVector<QPointF> Curves::getBasePoint() const
{
	return m_basePoints;
}