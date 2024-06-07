#include "externalFuncs.h"
#include "exercises.h"
#include <iostream>
#include <string>

/*	Форма для выбора решения.
*	в случае рассмотрения решений
*	как отдельных компонентов,
*	данный файл следует игнорировать */

const std::string g_theor_msg{ "У этого задания была только "
							   "теоретическая часть.\n" };
const std::string g_mult_msg{ "У этого решения несколько подзаданий. Они "
							   "будут выполняться последовательно.\n\n" };

int getNumOfEx() {
	while (true) {
		int exNum{};
		std::cin >> exNum;
		ignoreLine();

		// в случае появления новых решений добавлять case-ы
		switch (exNum) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
			return exNum;
		default:
			std::cout << "Неправильно введен номер задания. Попробуйте ещё раз.\n";
			std::cout << "Ваш выбор: ";
			break;
		}
	}
}

void getAnswer(int numberOfExercise) {
	switch (numberOfExercise) {
	case 1:
		chOne::chOneMain();
		break;
	case 2:
		chTwo::chTwoMain();
		break;
	case 3:
		chThree::chThreeMain();
		break;
	case 4:
		chFour::chFourMain();
		break;
	case 5:
		std::cout << g_theor_msg;
		break;
	case 6:
		std::cout << g_mult_msg;
		chSix::chSix_OneMain();
		std::cout << std::endl;
		chSix::chSix_TwoMain();
		std::cout << std::endl;
		chSix::chSix_threeMain();
		break;
	case 7:
		std::cout << g_mult_msg;
		chSeven::chSeven_OneMain();
		std::cout << std::endl;
		chSeven::chSeven_TwoMain();
		break;
	case 8:
		std::cout << g_mult_msg;
		chEight::chEight_OneMain();
		std::cout << std::endl;
		chEight::chEight_TwoMain();
		std::cout << std::endl;
		chEight::chEight_ThreeMain();
		std::cout << std::endl;
		chEight::chEight_FourMain();
		break;
	case 9:
		chNine::chNine_Main();
		break;
	case 10:
		std::cout << g_mult_msg;
		chTen::chTen_OneMain();
		std::cout << std::endl;
		chTen::chTen_TwoMain();
		std::cout << std::endl;
		chTen::chTen_ThreeMain();
		std::cout << std::endl;
		chTen::chTen_FourMain();
		std::cout << std::endl;
		chTen::chTen_FiveMain();
		break;
	case 11:
		chEleven::chElevenMain();
		break;
	default:
		break;
	}

}

int main() {
	std::setlocale(LC_ALL, "Russian");

	std::cout << "На данный момент готово 11 заданий.\n";
	std::cout << "Введите номер задания: ";
	int numOfEx{ getNumOfEx() };

	std::cout << std::endl;
	getAnswer(numOfEx);
}
