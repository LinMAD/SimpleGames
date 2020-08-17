#include <time.h>
#include "GameManager.h"

int main()
{
	srand((unsigned)time(static_cast<unsigned>(0)));

	GameManager g;

	g.run();

	return 0;
}