#pragma once

#include <ostream>
#include <string_view>

namespace poker {

enum class Suit {
  CLUBS = 0,
  DIAMONDS = 1,
  HEARTS = 2,
  SPADES = 3
};

enum class Value {
  TWO = 0,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  JACK,
  QUEEN,
  KING,
  ACE,
};

// Converts a case-insensitive character to a suit.
Suit SuitFromChar(char c);

// Converts a case-insensitive character to a value.
Value ValueFromChar(char c);

// Converts a suit to a character.
char SuitToChar(Suit s);

// Converts a value to a character.
char ValueToChar(Value v);

// This is an immutable primitive class that represents a generic card.
// TODO: generalize this further for other types of games?
class Card {
 public:
  // Defaults to 2c.
  Card();
  Card(Value value, Suit suit);
  Card(std::string_view str);
  
  Card(const Card&) = default;
  Card& operator=(const Card&) = default;
  Card(Card&&) = default;
  Card& operator=(Card&&) = default;
  ~Card() = default;

  Value value() const;
  Suit suit() const;

  // Comparison operators.
  // TODO: Add ordering operators if we can settle on a semantic.
  bool operator==(const Card& card) const;
  bool operator!=(const Card& card) const;

  // I/O operators.
  Card& operator=(std::string_view str);
  friend std::ostream& operator<<(std::ostream& out, const Card& card);

 private:
  Suit suit_;
  Value value_;
};

} // namespace poker