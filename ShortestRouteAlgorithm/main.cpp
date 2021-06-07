#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f

typedef struct {
	char nextPointName;
	int  distance;
}NEXT_POINT;

typedef struct {
	int		curVaule;
	char	name;
	int		linkNum;
	NEXT_POINT  nextPoint[5];
	string  route = "A";
}POINT;

void Dijkstra(POINT* startPoint, POINT* endPoint, POINT* piontArray, int pointNum)
{
	startPoint->curVaule = 0;
	startPoint->route = startPoint->name;

	std::vector<POINT> vecLeftPoints;
	for (int i = 0; i < pointNum; ++i) {
        if (piontArray[i].name != startPoint->name) {
            piontArray[i].route = startPoint->name;
            vecLeftPoints.push_back(piontArray[i]);
        }
	}

	while (true) {
		POINT expandPoint = *startPoint;
		//printf("startPoint->name = %c, startPoint->route = %s\n", startPoint->name, startPoint->route.data());

		if (expandPoint.name == endPoint->name) {
			*endPoint = expandPoint;
			break;
		}

		for (int i = 0; i < expandPoint.linkNum; ++i) {
			for (int j = 0; j < vecLeftPoints.size(); ++j) {
				if (expandPoint.nextPoint[i].nextPointName == vecLeftPoints[j].name) {
					if (vecLeftPoints[j].curVaule > expandPoint.nextPoint[i].distance + expandPoint.curVaule) {
						vecLeftPoints[j].curVaule = expandPoint.nextPoint[i].distance + expandPoint.curVaule;

						//update route
					    vecLeftPoints[j].route = expandPoint.route + vecLeftPoints[j].name;
					}
				}
			}
		}

        std::sort(vecLeftPoints.begin(), vecLeftPoints.end(), [](POINT a, POINT b){ return a.curVaule < b.curVaule; });

        *startPoint = vecLeftPoints[0];
        vecLeftPoints.erase(vecLeftPoints.begin());
	}
}

int main()
{
	POINT A, B, C, D, E, F;

	for (int i = 0; i < 6; ++i) {
        A.curVaule = INF;
        A.name = 'A';
        A.linkNum = 2;
        A.nextPoint[0].nextPointName = 'B';
        A.nextPoint[0].distance = 6;
        A.nextPoint[1].nextPointName = 'C';
        A.nextPoint[1].distance = 3;

        B.curVaule = INF;
        B.name = 'B';
        B.linkNum = 3;
        B.nextPoint[0].nextPointName = 'A';
        B.nextPoint[0].distance = 6;
        B.nextPoint[1].nextPointName = 'C';
        B.nextPoint[1].distance = 2;
        B.nextPoint[2].nextPointName = 'D';
        B.nextPoint[2].distance = 5;

        C.curVaule = INF;
        C.name = 'C';
        C.linkNum = 4;
        C.nextPoint[0].nextPointName = 'A';
        C.nextPoint[0].distance = 3;
        C.nextPoint[1].nextPointName = 'B';
        C.nextPoint[1].distance = 2;
        C.nextPoint[2].nextPointName = 'D';
        C.nextPoint[2].distance = 3;
        C.nextPoint[3].nextPointName = 'E';
        C.nextPoint[3].distance = 4;

        D.curVaule = INF;
        D.name = 'D';
        D.linkNum = 4;
        D.nextPoint[0].nextPointName = 'B';
        D.nextPoint[0].distance = 5;
        D.nextPoint[1].nextPointName = 'C';
        D.nextPoint[1].distance = 3;
        D.nextPoint[2].nextPointName = 'E';
        D.nextPoint[2].distance = 2;
        D.nextPoint[3].nextPointName = 'F';
        D.nextPoint[3].distance = 3;

        E.curVaule = INF;
        E.name = 'E';
        E.linkNum = 3;
        E.nextPoint[0].nextPointName = 'C';
        E.nextPoint[0].distance = 4;
        E.nextPoint[1].nextPointName = 'D';
        E.nextPoint[1].distance = 2;
        E.nextPoint[2].nextPointName = 'F';
        E.nextPoint[2].distance = 5;

        F.curVaule = INF;
        F.name = 'F';
        F.linkNum = 2;
        F.nextPoint[0].nextPointName = 'D';
        F.nextPoint[0].distance = 3;
        F.nextPoint[1].nextPointName = 'E';
        F.nextPoint[1].distance = 5;

        POINT array[10] = { A, B, C, D, E, F};

        POINT endPoint = array[i];
        Dijkstra(&A, &endPoint, array, 6);
        cout << "Shortest route: "<< endPoint.route << endl <<"Length of shortest route: "<< endPoint.curVaule  << endl;
	}
}


