#include <iostream>


#include "string_bst.hpp"
#include "max_heap.hpp"
#include "text_item.hpp"
#include "util.hpp"

using namespace std;

//--- PART 1A: Implementation and testing of heap insert
void heap_insert_tests(max_heap &hp) {
	text_item temp;
	std::string word = "item";
	int random_num;
	long int seed = long(time(0));    // seed for random number generator
	srand(seed);
	
	//--- Testing insert functionality
	std::cout << "*** TESTING INSERT ***" << std::endl;
	//--- This adds 5 items to the heap with random numbers
	//    and prints out the top, but it does not fully 
	//    test the correctness of the insert function.
	for (int i = 0 ; i < 5; i++) {
		random_num = rand() % 100;
		string text = word;
		text += std::to_string(i+1);
		std::cout << "adding " << text << ",  with number " << random_num << " to heap" << std::endl;
		hp.insert(text_item{text, random_num});	
		temp = hp.top();
		std::cout << "Top of heap is: " << temp << std::endl;		
	}
	
	//--- Specific insert functionality that should be tested:
	
	// insert without any swap_ups needed
		std::cout << std::endl;
		std::cout << "*** MY TEST: No swap ups needed. ***" << std::endl;
		int testNum = 0;
		string testString = "test";
		//test
		hp.insert(text_item{testString, testNum});
		//set temp for comparison
		std::cout << "Item in last index is String-test Freq-0: " << hp.bottom() << std::endl;
		
	// insert with a swap_up / multiple swap_ups
		std::cout << std::endl;
		std::cout << "*** MY TEST: Multiple swap ups needed. ***" << std::endl;
		int testNumSwap = 500;
		string testStringSwap = "testSwap";
		//test
		hp.insert(text_item{testString, testNumSwap});
		//set temp for comparison
		std::cout << "Item in first index is String-testSwap Freq-500: " << hp.top() << std::endl;
	}

//--- PART 1B: Implementation and testing of heap delete
void heap_delete_tests(max_heap &hp) {
	text_item temp;
	
	//--- Testing deleteMax functionality
	std::cout << "*** TESTING DELETEMAX ***" << std::endl;
	//--- This does not fully test delete_max functionality.
	if (hp.size() > 1) {
		std::cout << "Item returned from heap delete: "<< hp.delete_max(); << std::endl;
		std::cout << "Top of heap is now: " << hp.top() << std::endl;	
	}
    
    std::cout << "*** CURRENT ARRAY ***" << std::endl;
    for(int i = 0; i < hp.size(); i++){
		hp.print(i);
	}

	//--- Specific delete functionality that should be tested:
	//clear hp
	for(int i = 0; i < hp.size(); i++){
		hp.delete_max();
	}

    std::cout << "*** CURRENT ARRAY ***" << std::endl;
    for(int i = 0; i < hp.size(); i++){
		hp.print(i);
	}

    hp.insert(text_item{"testitem0", 0});
    hp.insert(text_item{"testitem1", 1});
    hp.insert(text_item{"testitem5", 5});
    hp.insert(text_item{"testitem2", 2});
    hp.insert(text_item{"testitem3", 3});
    hp.insert(text_item{"testitem4", 4});
    hp.insert(text_item{"testitem6", 6});
    hp.insert(text_item{"testitem7", 7});
    hp.insert(text_item{"testitem9", 9});
    hp.insert(text_item{"testitem8", 8});

    //print current array:
    std::cout << "*** CURRENT ARRAY ***" << std::endl;
    for(int i = 0; i < hp.size(); i++){
		hp.print(i);
	}

    std::cout << "Top of heap is now (testitem1,130): " << hp.top() << std::endl;
	// remove_max works when swap_down with right child
    std::cout << "Item returned from heap delete (obviousMax, 999): "<< hp.delete_max() << std::endl;
    std::cout << "Top of heap is now: " << hp.top() << std::endl;
		
	// remove_max works when swap_down with left child
    std::cout << "Item returned from heap delete (testitem5, 125): "<< hp.delete_max() << std::endl;
    std::cout << "Top of heap is now: " << hp.top() << std::endl;
		
	// remove_max on an empty heap (should throw exception similar to top())
		// <INSERT TEST(S) HERE>
		
}

//--- PART 2: Implementation and testing of BST word_frequency
void tree_tester(string_bst const &tree) {
	std::cout << std::endl << "BEGINNING TESTS FOR PART 2" << std::endl;
	
	//--- Testing word_frequency functionality
	//--- This does not fully test word_frequency functionality.
	if (tree.size() > 1) {
		string to_find = "difficult";
		int num_times = tree.word_frequency(to_find);
		std::cout << "Found: "<< to_find << 
			" in the input file " << num_times 
			<< " time(s)." << std::endl;
	}
	
	//--- Specific word_frequency functionality that should be tested:
	
	// can search through both left and right subtrees if not found at current node
		// <INSERT TEST(S) HERE>
		
	// returns 0 if word is not found
		// <INSERT TEST(S) HERE>
			
}

//--- PART 3: Implementation and testing of word frequency analysis
void overall_most_freq(max_heap hp) {
	std::cout << "*** Top 5 most frequent words: ***" << std::endl;
	
	//--- Add your code to print out the 5 most frequent words below:
	if (hp.size() > 1) {
		std::cout << "Most frequent text item: " << hp.top() << std::endl;
	}
	for(int i = 0; i < 5; i++){
		cout << hp.delete_max() << endl;
	}

}

void at_least_length(max_heap hp, size_t num_letters) {
	cout << "*** Top 5 most frequent words with at least " 
		<< num_letters << " letters ***" << std::endl;
		
	//--- Add code to print out the 5 most common
	//--- words of length at least <num_letters>
	max_heap* atLeast = new max_heap(hp.size());

	for(int i = 0; i < hp.size(); i++){
		text_item highest = hp.delete_max();
		if(highest.word.length() >= num_letters){
			(*atLeast).insert(highest);
		}
	}

	overall_most_freq(*atLest);

}

void starts_with(max_heap hp, char starts_with_letter) {
	cout << "*** Top 5 most frequent words that begin with " 
		<< starts_with_letter << " ***" << std::endl;

		max_heap* startsWith = new max_heap(hp.size());

		
	//--- Add code to print out the 5 most common words
	//--- that start with the letter <starts_with_letter>
	for(int i = 0; i < hp.size(); i++){
		text_item highest = hp.delete_max();
		if(highest.word.at(0) == starts_with_letter){
			(*startsWith).insert(highest);
		}
	}

	overall_most_freq(*startsWith);
	
}

void heap_tester() {	
	text_item temp;
	int heap_size = 15; //feel free to create heaps of other sizes when testing
	//cout << "How many items should be added to heap? ";
	//cin >> heap_size;
	max_heap hp(heap_size);
	std::cout << "Created heap of size " << heap_size << std::endl;
		
	//--- Testing heap size and top
	std::cout << "Current number of items in heap is: " << hp.size() << std::endl;
	try {
		temp = hp.top(); //should throw and exception without items in heap
		std::cout << "Top of heap is: " << temp << std::endl;	
	} catch (std::logic_error e) {
		std::cout << e.what() << std::endl;
	}
	// PART 1A:
	std::cout << std::endl << "BEGINNING TESTS FOR PART 1A" << std::endl;
	heap_insert_tests(hp);
	// PART 1B:
	std::cout << std::endl << "BEGINNING TESTS FOR PART 1B" << std::endl;
	heap_delete_tests(hp);
}

void text_analysis_tester(string_bst &tree) {
	std::cout << std::endl << "BEGINNING TESTS FOR PART 3" << std::endl;
	overall_most_freq(copy_to_heap(tree));
	std::cout << std::endl;
	at_least_length(copy_to_heap(tree), 8); // change the 8 to test other string-lengths
	std::cout << std::endl;
	starts_with(copy_to_heap(tree), 'c'); // change the 'c' to test words that starts_with_letter
											// with different characters
}

int main(int argc, char* argv[]) {
	
	//--- Part 1: max_heap implementation
	heap_tester(); 
	
	//--- Part 2: string_bst implementation
	string_bst tree;
	load_bst("sample1.txt", tree); // create a bst from an input file.
	tree_tester(tree);			//sample2.txt contains a much bigger file
	
	//--- Part 3: word frequency analysis of text files
	text_analysis_tester(tree);

}
