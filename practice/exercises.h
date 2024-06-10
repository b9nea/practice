#ifndef EXERCISES_H
#define EXERCISES_H

namespace chOne {
	int chOneMain();
}

namespace chTwo {
	int chTwoMain();
}

namespace chThree {
	int chThreeMain();
}

namespace chFour {
	int chFourMain();
}

namespace chFive {
	int chFiveMain();
}

namespace chSix {
	int chSix_OneMain();
	int chSix_TwoMain();
	bool passOrFail();
	int chSix_threeMain();
}

namespace chSeven {
	double calculateHeight(double initialHeight, int seconds);
	bool calculateAndPrintHeight(double initialHeight, int time);
	int chSeven_OneMain();
	bool isPrime(int x);
	int chSeven_TwoMain();
}

namespace chEight {
	using degrees_t = double;
	using radians_t = double;

	radians_t convertToRadians(degrees_t degrees);
	int chEight_OneMain();
	int chEight_TwoMain();
	int chEight_ThreeMain();
	int chEight_FourMain();
}

namespace chNine {
	enum class MonsterType{};
	struct Monster{};
	void printMonster(Monster monster);
	int chNine_Main();
}

namespace chTen {
	int chTen_OneMain();
	int chTen_TwoMain();
	int chTen_ThreeMain();
	int chTen_FourMain();
	int chTen_FiveMain();
}

namespace chEleven {
	int chElevenMain();
}

#endif
