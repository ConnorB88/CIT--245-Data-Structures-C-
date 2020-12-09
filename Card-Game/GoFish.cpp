#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>

using std::vector;
using std::string;

/*
	Creating the data for the cards and creating structs to hold all of the data for the card, deck, player, and game.
*/
enum  Rank { ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};
enum  Suit { SPADES, HEARTS, DIAMONDS, CLUBS};

struct Card {
	Rank rank;
	Suit suit;
	int num_suits = 4;
	int num_ranks = 13;
};

struct Deck {
	vector<Card> cards;
};

struct Player {
	vector<Card> hand;
	int score = 0;
};

struct Game {
	vector<Player> players;
	Deck deck;
	int num_players = 2;
	int num_cards_per_hand = 7;
};

/*
Making the protoypes for the functions that are to be used. 
*/
void initialize(Deck&);
void print_deck(const Deck&);
void print_card(const Card&);
void shuffle(Deck&);
bool deal_cards(Game&);
void print_hand(const vector<Card>&);
void print_hands(const Game&);
void initialize(Game&);
void add_players(Game&);
void play(Game&);
Rank get_rank(const vector<Card>&);
bool is_match(const Game&, size_t, Rank);
void take_card(Game&, size_t, Rank);
void draw_card(Game&, size_t);
void check_for_score(Player&);

int main() 
{
	Game game; // creating the game
	play(game); // playing the game
	print_hands(game); // printing both of the hands
}

void initialize(Deck& deck) // initializing the deck
{
   	Card card;
		for (int suit = 0; suit < card.num_suits; suit++)
		{
			for (int rank = 0; rank < card.num_ranks; rank++) {
				card.suit = Suit(suit);
				card.rank = Rank(rank);
				deck.cards.push_back(card);
			}
		}
	}// end initialize

void print_deck(const Deck& deck) // printing the deck
{
	for (Card c : deck.cards) 
	{
		print_card(c);
	}
}

void print_card(const Card& card)  // printing the cards to the screen
{
	std::cout << "Rank = " << card.rank << "  " << "Suit = " << card.suit << '\n';
}

void shuffle(Deck& deck) // shuffling the deck
{
	Deck shuffled;
	while (!deck.cards.empty()) 
	{
		size_t rand_index = rand() % deck.cards.size();
		shuffled.cards.push_back(deck.cards[rand_index]);
		deck.cards.erase(deck.cards.begin() + rand_index);
	}
	deck = shuffled;
}

bool deal_cards(Game& game) // dealing the cards to the players hands
{
	if (game.deck.cards.size() < game.num_players * game.num_cards_per_hand)
	{
		return false;
	}

	for (int card = 0; card < game.num_cards_per_hand; card++)
	{
		for (int player = 0; player < game.num_players; player++) 
		{
			game.players[player].hand.push_back(game.deck.cards[0]);
			game.deck.cards.erase(game.deck.cards.begin());
		}
	}
	return true;
}

void print_hand(const vector<Card>& hand) // printing the hand
{
	for (Card c : hand)
	{
		print_card(c);
	}
} 

void print_hands(const Game& game)// print both of the players hands 
{
	for (int player = 0; player < game.num_players; player++)
	{
		print_hand(game.players[player].hand);
		std::cout << '\n';
	}
	print_deck(game.deck);
}

void initialize(Game& game)// initializing the game
{
	initialize(game.deck); 
	shuffle(game.deck);
	add_players(game);
}

void add_players(Game& game) // adding players to the game
{
	for (int player = 0; player < game.num_players; player++) 
	{
		Player new_player;
		game.players.push_back(new_player);
	}
}


Rank get_rank(const vector<Card>& hand) // data validation of the rank(checking if that card rank is acutually in the players hand)
{
	bool valid = false;
	int rank;
	while (!valid)
	{
		std::cout << "Please enter a rank: ";
		std::cin >> rank;
		for (Card c : hand) 
		{
			if (c.rank == Rank(rank)) 
			{
				valid = true;
			}
		}
	}
	return Rank(rank);
}

void display_state(const Game& game, size_t player)// displaying your hand/score and your opponent hand/score to the screen.
{
	std::cout << "Your hand: \n";
	print_hand(game.players[player].hand);
	std::cout << "Your score = " << game.players[player].score << '\n';
	std::cout << "Opponent's hand: \n";
	size_t opponent = (player + 1) % game.num_players;
	print_hand(game.players[opponent].hand);
	std::cout << "Opponents score: " << game.players[opponent].score << '\n';
	std::cout << '\n';
}

bool is_match(const vector<Card>& hand, Rank chosen_rank)// checking if the card rank you choose matches your opponents card rank
{
	bool match = false;
	for (Card c : hand)
	{
		if (c.rank == chosen_rank)
		{
			match = true;
		}
	}
	return match;
} 

void take_card(Game& game, size_t current_player, Rank chosen_rank) // if there is a match take the card
{
	size_t next_player = (current_player + 1) % game.num_players;
	bool card_taken = false;
	size_t card_index = 0;
	while (!card_taken)
	{
		Card current_card = game.players[next_player].hand[card_index];
		if (current_card.rank == chosen_rank)
		{
			game.players[current_player].hand.push_back(current_card);
			game.players[next_player].hand.erase(game.players[next_player].hand.begin() + card_index);
			card_index = true;
		}
		card_index++;
	}
}

void draw_card(Game& game, size_t player)// drawing the cards and putting it in the players hand and erasing it from the deck
{
	if (game.deck.cards.empty())
	{
		return;
	}
	else
	{
		game.players[player].hand.push_back(game.deck.cards[0]);
		game.deck.cards.erase(game.deck.cards.begin());
	}
}

void check_for_score(Player& player)// the function checks for the score and adds a point if the marked cards are both the same.
{
	vector<bool> marked(player.hand.size(), false);
	for (size_t i = 0; i < player.hand.size() - 1; i++)
	{
		for (size_t j = i + 1; j < player.hand.size(); j++)
		{
			if (!marked[i] && !marked[j] && player.hand[i].rank == player.hand[j].rank)
			{
				marked[i] = true;
				marked[j] = true;
				player.score++;
			}
		}
	}
	size_t card = 0;
	while (!player.hand.empty() && card < marked.size())
	{
		if (marked[card])
		{
			player.hand.erase(player.hand.begin() + card);
			marked.erase(marked.begin() + card);
		}
		else
		{
			card++;
		}
	}
}

void play(Game& game) // playing the game
{
	initialize(game);
	deal_cards(game);

	bool game_over = false;
	size_t player = 0;
	while (!game_over)
	{
		display_state(game, player);

		Rank rank = get_rank(game.players[player].hand);

		size_t next_player = (player + 1) % game.num_players;

		if (is_match(game.players[next_player].hand, rank))
		{
			take_card(game, player, rank);
		}
		else
		{
			std::cout << "Go fish.";
			draw_card(game, player);
		}
		check_for_score(game.players[player]);

		if (game.players[player].hand.empty())
		{
			game_over = true;
		}
		player = next_player;
	}
	// displays the end of the game
	std::cout << "Game is over.";
	for (size_t player = 0; player < game.players.size(); player++)
	{
		std::cout << "Player " << player << "'s score is" << game.players[player].score 
			<< '\n';
	}
}