#include "externalFuncs.h"
#include "constants.h"
#include <array>
#include <algorithm>
#include <cstddef>
#include <cassert>
#include <numeric>
#include <string>
#include <vector>
#include <numeric>
#include <iostream>
#include <random>
#include <ctime>
#include <iterator>

/*	Решения заданий из последних резюме глав.
*	При использовании их как отдельных компонентов
*	следует добавлять следующую строку:
*	std::setlocale(LC_ALL, "Russian");
*	Без неё консоль не будет поддерживать русский язык.
*/

namespace chOne {
	int chOneMain() {
		std::cout << "Ввод двух чисел." << "\n";
		int x{ getInt() };
		int y{ getInt() };
		std::cout << x << " + " << y << " = " << x + y << '\n';
		std::cout << x << " - " << y << " = " << x - y << '\n';

		return 0;
	}

}

namespace chTwo {
	int chTwoMain() {
		std::cout << "Ввод двух чисел и их сложение." << "\n";
		int x{ getInt() };
		int y{ getInt() };
		writeAnswer(x + y);

		return 0;
	}
}

namespace chThree {
	int chThreeMain() {
		std::cout << "Целочисленное деление двух чисел.\n";
		int x{ getInt() };
		int y{ getInt() };
		writeAnswer(x / y);

		return 0;
	}
}

namespace chFour {
	int chFourMain() {
		std::cout << "Примитивный калькулятор.\n";
		double x{ getDouble() };
		double y{ getDouble() };
		char operation{ getOperator() };
		calculate(x, operation, y);

		return 0;
	}
}

namespace chFive {
	// теоретические задания. Файл: *типагитхаб*
}

namespace chSix {
	int chSix_OneMain() {
		std::cout << "Требуется ввод положительного числа.\n";
		int num{ getInt() };

		if (num < 0) {
			num = -num;
		}

		std::cout << "Вы ввели: " << num << "\n";

		return 0;
	}

	int chSix_TwoMain() {
		std::cout << "Сколько студентов в вашей группе?\n";
		int students{ getInt() };

		if (students > constants::max_class_size)
			std::cout << "Слишком много студентов в группе\n";
		else
			std::cout << "Небольшая группа\n";

		return 0;
	}

	bool passOrFail() {
		static int passes{ 3 };
		return (--passes >= 0);
	}

	int chSix_threeMain() {
		std::cout << "User #1: " << (passOrFail() ? "Pass\n" : "Fail\n");
		std::cout << "User #2: " << (passOrFail() ? "Pass\n" : "Fail\n");
		std::cout << "User #3: " << (passOrFail() ? "Pass\n" : "Fail\n");
		std::cout << "User #4: " << (passOrFail() ? "Pass\n" : "Fail\n");
		std::cout << "User #5: " << (passOrFail() ? "Pass\n" : "Fail\n");

		return 0;
	}
}

namespace chSeven {
	double calculateHeight(double initialHeight, int seconds) {
		double distanceFallen{ constants::gravity * seconds * seconds / 2 };
		double heightNow{ initialHeight - distanceFallen };

		if (heightNow < 0.0)
			return 0.0;
		else
			return heightNow;
	}

	bool calculateAndPrintHeight(double initialHeight, int time) {
		double currentHeight = calculateHeight(initialHeight, time);
		std::cout << "В " << time << " секунд мяч находится на высоте: " << currentHeight << "\n";

		return (currentHeight == 0.0);
	}

	int chSeven_OneMain() {
		std::cout << "Узнаём высоту башни в метрах.\n";
		double initialHeight{ getDouble() };
		int seconds = 0;

		bool hitGround = false;
		do {
			hitGround = calculateAndPrintHeight(initialHeight, seconds++);
		} while (!hitGround);

		return 0;
	}

	bool isPrime(int x)
	{
		int divisors{ 1 };

		for (int test{ 2 }; test <= x; ++test) {
			if (x % test == 0)
				++divisors;
		}

		return (divisors == 2);
	}

	int chSeven_TwoMain() {
		assert(!isPrime(0));
		assert(!isPrime(1));
		assert(isPrime(2));
		assert(isPrime(3));
		assert(!isPrime(4));
		assert(isPrime(5));
		assert(isPrime(7));
		assert(!isPrime(9));
		assert(isPrime(11));
		assert(isPrime(13));
		assert(!isPrime(15));
		assert(!isPrime(16));
		assert(isPrime(17));
		assert(isPrime(19));
		assert(isPrime(97));
		assert(!isPrime(99));
		assert(!isPrime(99));
		assert(isPrime(13417));

		std::cout << "Успешно!\n";

		return 0;
	}
}

namespace chEight {
	using degrees_t = double;
	using radians_t = double;

	radians_t convertToRadians(degrees_t degrees) {
		return degrees * constants::pi / 180;
	}
	int chEight_OneMain() {
		std::cout << "Подзадание 2a.\n";

		std::cout << "Получаем градусы.\n";
		degrees_t degrees{ getDouble() };

		radians_t radians{ convertToRadians(degrees) };
		std::cout << degrees << " градусов = " << radians << " радиан.\n";

		return 0;
	}

	template <typename T>
	T add(T x, T y)
	{
		return x + y;
	}

	int chEight_TwoMain() {
		std::cout << "Подзадание 5a.\n";

		std::cout << add(2, 3) << '\n';
		std::cout << add(1.2, 3.4) << '\n';

		return 0;
	}

	template <typename T>
	T mult(T x, int y)
	{
		return x * y;
	}

	int chEight_ThreeMain() {
		std::cout << "Подзадание 5b.\n";

		std::cout << mult(2, 3) << '\n';
		std::cout << mult(1.2, 3) << '\n';

		return 0;
	}

	template <typename T, typename U>
	auto sub(T x, U y)
	{
		return x - y;
	}

	int chEight_FourMain() {
		std::cout << "Подзадание 5c.\n";

		std::cout << sub(3, 2) << '\n';
		std::cout << sub(3.5, 2) << '\n';
		std::cout << sub(4, 1.5) << '\n';

		return 0;
	}
}

namespace chNine {
	enum class MonsterType {
		ogre,
		dragon,
		orc,
		giant_spider,
		slime
	};

	struct Monster {
		MonsterType type{};
		std::string name{};
		int health{};
	};

	std::string getMonsterTypeString(MonsterType type) {
		switch (type)
		{
		case MonsterType::ogre:
			return "Огр";
		case MonsterType::dragon:
			return "Дракон";
		case MonsterType::orc:
			return "Орк";
		case MonsterType::giant_spider:
			return "Гигантский паук";
		case MonsterType::slime:
			return "Слизень";
		}

		return "Unknown";
	}

	void printMonster(Monster monster) {
		std::cout << "Это " << getMonsterTypeString(monster.type) <<
			" по имени " << monster.name <<
			", имеющий " << monster.health << " здоровья.\n";
	}

	int chNine_Main() {
		Monster ogre{ MonsterType::ogre, "Торг", 145 };
		Monster slime{ MonsterType::slime, "Блурп", 23 };

		printMonster(ogre);
		printMonster(slime);

		return 0;

		return 0;
	}
}

namespace chTen {
	enum ItemTypes {
		item_health_potion,
		item_torch,
		item_arrow,
		max_items
	};

	using inventory_type = std::array<int, ItemTypes::max_items>;

	int countTotalItems(const inventory_type& items) {
		return std::reduce(items.begin(), items.end());
	}

	int chTen_OneMain() {
		inventory_type items{ 2, 5, 10 };

		std::cout << "У игрока всего " << countTotalItems(items) << " предметов.\n";
		std::cout << "У игрока всего " << items[ItemTypes::item_torch] << " факелов\n";

		return 0;
	}

	struct Student {
		std::string name{};
		int grade{};
	};

	int getNumberOfStudents() {
		int numberOfStudents{};

		do {
			std::cout << "Сколько всего студентов вы хотите ввести?\n";
			numberOfStudents = getInt();
		} while (numberOfStudents <= 0);

		return numberOfStudents;
	}

	std::vector<Student> getStudents() {
		using vector_type = std::vector<Student>;

		int numberOfStudents{ getNumberOfStudents() };
		vector_type students(static_cast<vector_type::size_type>(numberOfStudents));
		int studentNumber{ 1 };

		for (auto& student : students) {
			std::cout << "Введите имя #" << studentNumber << ": ";
			std::cin >> student.name;
			std::cout << "Введите оценку #" << studentNumber << ".\n";
			student.grade = getInt();

			++studentNumber;
		}

		return students;
	}

	bool compareStudents(const Student& a, const Student& b) {
		return (a.grade > b.grade);
	}

	int chTen_TwoMain() {
		auto students{ getStudents() };

		std::sort(students.begin(), students.end(), compareStudents);

		for (const auto& student : students)
		{
			std::cout << student.name << " получил оценку " << student.grade << '\n';
		}

		return 0;
	}

	void swap(int& a, int& b) {
		int temp{ a };

		a = b;
		b = temp;
	}

	int chTen_ThreeMain() {
		int a{ 6 };
		int b{ 8 };
		swap(a, b);

		if (a == 8 && b == 6)
			std::cout << "Работает!\n";
		else
			std::cout << "Не работает!\n";

		return 0;
	}

	void printCString(const char* str) {
		while (*str != '\0') {
			std::cout << *str;

			++str;
		}
	}

	int chTen_FourMain() {
		printCString("Hello world!");

		std::cout << '\n';

		return 0;
	}

	enum class BlackjackResult
	{
		player_win,
		dealer_win,
		tie
	};

	enum class CardSuit{
		suit_club,
		suit_diamond,
		suit_heart,
		suit_spade,

		max_suits
	};

	enum class CardRank{
		rank_2,
		rank_3,
		rank_4,
		rank_5,
		rank_6,
		rank_7,
		rank_8,
		rank_9,
		rank_10,
		rank_jack,
		rank_queen,
		rank_king,
		rank_ace,

		max_ranks
	};

	struct Card{
		CardRank rank{};
		CardSuit suit{};
	};

	struct Player{
		int score{};
	};

	using deck_type = std::array<Card, 52>;
	using index_type = deck_type::size_type;

	constexpr int maximumScore{ 21 };
	constexpr int minimumDealerScore{ 17 };

	void printCard(const Card& card){
		switch (card.rank){
		case CardRank::rank_2:      std::cout << '2';   break;
		case CardRank::rank_3:      std::cout << '3';   break;
		case CardRank::rank_4:      std::cout << '4';   break;
		case CardRank::rank_5:      std::cout << '5';   break;
		case CardRank::rank_6:      std::cout << '6';   break;
		case CardRank::rank_7:      std::cout << '7';   break;
		case CardRank::rank_8:      std::cout << '8';   break;
		case CardRank::rank_9:      std::cout << '9';   break;
		case CardRank::rank_10:     std::cout << 'T';   break;
		case CardRank::rank_jack:   std::cout << 'J';   break;
		case CardRank::rank_queen:  std::cout << 'Q';   break;
		case CardRank::rank_king:   std::cout << 'K';   break;
		case CardRank::rank_ace:    std::cout << 'A';   break;
		default:
			std::cout << '?';
			break;
		}

		switch (card.suit){
		case CardSuit::suit_club:       std::cout << 'C';   break;
		case CardSuit::suit_diamond:    std::cout << 'D';   break;
		case CardSuit::suit_heart:      std::cout << 'H';   break;
		case CardSuit::suit_spade:      std::cout << 'S';   break;
		default:
			std::cout << '?';
			break;
		}
	}

	int getCardValue(const Card& card){
		if (card.rank <= CardRank::rank_10){
			return (static_cast<int>(card.rank) + 2);
		}

		switch (card.rank){
		case CardRank::rank_jack:
		case CardRank::rank_queen:
		case CardRank::rank_king:
			return 10;
		case CardRank::rank_ace:
			return 11;
		default:
			return 0;
		}
	}

	void printDeck(const deck_type& deck){
		for (const auto& card : deck){
			printCard(card);
			std::cout << ' ';
		}

		std::cout << '\n';
	}

	deck_type createDeck(){
		deck_type deck{};
		index_type card{ 0 };

		auto suits{ static_cast<int>(CardSuit::max_suits) };
		auto ranks{ static_cast<int>(CardRank::max_ranks) };

		for (int suit{ 0 }; suit < suits; ++suit){
			for (int rank{ 0 }; rank < ranks; ++rank){
				deck[card].suit = static_cast<CardSuit>(suit);
				deck[card].rank = static_cast<CardRank>(rank);
				++card;
			}
		}

		return deck;
	}

	void shuffleDeck(deck_type& deck){
		static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

		std::shuffle(deck.begin(), deck.end(), mt);
	}

	bool playerWantsHit(){
		while (true){
			// «еще» - hit (h), «достаточно» - stand (s)
			std::cout << "(h) - «еще», или (s) - «достаточно»: ";

			char ch{};
			std::cin >> ch;

			switch (ch)
			{
			case 'h':
				return true;
			case 's':
				return false;
			}
		}
	}

	bool playerTurn(const deck_type& deck, index_type& nextCardIndex, Player& player){
		while (true){
			if (player.score > maximumScore){
				std::cout << "У Вас перебор!\n";
				return true;
			}
			else{
				if (playerWantsHit()){
					int cardValue{ getCardValue(deck[nextCardIndex++]) };
					player.score += cardValue;
					std::cout << "Вы взяли " << cardValue
						<< " и теперь у Вас " << player.score << '\n';
				}
				else{
					return false;
				}
			}
		}
	}

	bool dealerTurn(const deck_type& deck, index_type& nextCardIndex, Player& dealer){
		while (dealer.score < minimumDealerScore){
			int cardValue{ getCardValue(deck[nextCardIndex++]) };
			dealer.score += cardValue;
			std::cout << "Дилер взял " << cardValue
				<< " и теперь у него " << dealer.score << '\n';

		}

		if (dealer.score > maximumScore){
			std::cout << "У дилера перебор!\n";
			return true;
		}

		return false;
	}

	BlackjackResult playBlackjack(const deck_type& deck){
		index_type nextCardIndex{ 0 };

		Player dealer{ getCardValue(deck[nextCardIndex++]) };

		std::cout << "Дилер показывает: " << dealer.score << '\n';

		Player player{ getCardValue(deck[nextCardIndex]) + getCardValue(deck[nextCardIndex + 1]) };
		nextCardIndex += 2;

		std::cout << "У Вас: " << player.score << '\n';

		if (playerTurn(deck, nextCardIndex, player)){
			return BlackjackResult::dealer_win;
		}

		if (dealerTurn(deck, nextCardIndex, dealer)){
			return BlackjackResult::player_win;
		}

		if ((player.score == dealer.score) && playerTurn(deck, nextCardIndex, player) == false){
			return BlackjackResult::tie;
		}

		if (player.score > dealer.score); {
			return BlackjackResult::player_win;
		}
	}

	int chTen_FiveMain(){
		auto deck{ createDeck() };

		shuffleDeck(deck);

		if (playBlackjack(deck) == BlackjackResult::player_win){
			std::cout << "Вы выиграли!\n";
		}
		else if (playBlackjack(deck) == BlackjackResult::dealer_win) {
			std::cout << "Вы проиграли!\n";
		}
		else if (playBlackjack(deck) == BlackjackResult::tie) {
			std::cout << "Ничья!\n";
		}

		return 0;
	}
}

namespace chEleven {
	int binarySearch(const int* array, int target, int min, int max){
		assert(array);

		if (min > max) {
			return -1;
		}

		int midpoint{ std::midpoint(min, max) };

		if (array[midpoint] > target){
			return binarySearch(array, target, min, midpoint - 1);
		}
		else if (array[midpoint] < target){
			return binarySearch(array, target, midpoint + 1, max);
		}
		else{
			return midpoint;
		}
	}

	int chElevenMain(){
		constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };
		constexpr int numTestValues{ 9 };
		constexpr int testValues[numTestValues]{ 0, 3, 12, 13, 22, 26, 43, 44, 49 };
		int expectedValues[numTestValues]{ -1, 0, 3, -1, -1, 8, -1, 13, -1 };

		for (int count{ 0 }; count < numTestValues; ++count){
			int index{ binarySearch(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };
			if (index == expectedValues[count])
				std::cout << "тестовая величина " << testValues[count] << ": passed!\n";
			else
				std::cout << "тестовая величина " << testValues[count] << ": failed.  С кодом что-то не так!\n";
		}

		return 0;
	}
}