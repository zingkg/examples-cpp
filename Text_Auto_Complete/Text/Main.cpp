#include <iostream>
#include <string>
#include "Word.h"
#include "Phrase.h"
#include "Sentence.h"
#include "Dict.h"

int main () {
	const Dict dictionary("new-data.txt");	// Construct a dictionary from txt file

	std::cout << "Search: ";		// Query the user
  std::string input;
	std::getline(std::cin, input);	// Get the line from the user
	std::cout << std::endl;			// Add a new line to make it look better

  // If not -1, keep asking
	while (input.compare("-1") != 0) {
    std::string compareS = input;

		// Erase the last character, should be ' ', '\t', '.'
		compareS.erase(compareS.end() - 1);

    // Word completion, if '\t'
		if (input.compare(compareS + "\t") == 0) {
			Word w(compareS);					// Word is input without end char
			w.complete(dictionary);			// Construct complete dictionary
			w.check(dictionary);			// Construct check dictionary

			// Show the Top10Complete and Top10Check
			w.show();
		}

    // Phrase completion, if ' '
		if (input.compare(compareS + " ") == 0) {
			Phrase p(compareS);
			p.complete(dictionary);			// Construct complete dictonary
			p.check(dictionary);			// Construct check dictionary

			// Show the Top10Complete and Top10Check
			p.show();
		}

    // Sentence completion, if '.'
		if (input.compare(compareS + ".") == 0) {
			Sentence s(compareS);
			s.complete(dictionary);
			s.check(dictionary);
			s.show();
		}

		std::cout << "Search: ";
		std::getline(std::cin, input);
	}	// End while

	return 0;
}
