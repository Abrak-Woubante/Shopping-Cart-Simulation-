/*
* Name: Abrak Woubante, 5007305246, AS4
* Description: Storefront 
* Input: txt files
* Output: shopping cart and total 
*/
#include "shopping_cart.h"

/*
* function_identifier: add the item parameter to the end of the items array
* parameters: Item
* return value: none
*/
void ShoppingCart::addItem(Item* item)
{
	//This should add the item parameter to the end of the items array.
	//If the items array does not have space to add the item,
	// the array should be made bigger using the resize function before adding the item
	//Add the item to the end of the array and increment the itemCount to count the newly added item
	//TODO: Finish the function

	if(itemCount==itemsArrSize){
	resizeArray();//call the resizeArray
	}

	items[itemCount]=item;//MAYBE CHANGE TO ITEM COUNT
	itemCount++;
}

/*
* function_identifier: make the items array bigger
* parameters: none
* return value: none
*/
void ShoppingCart::resizeArray()
{
	
	//This should make the items array bigger by the const RESIZE_AMOUNT.
	//For example, if the array had 7 elements and RESIZE_AMOUNT is 4, the array afterwards should have 11 elements
	
	//Make a new, bigger array
	//Then, copy over the elements from the old array (do not delete the old items!!!)
	//Deallocate the old array (Remember how to specifically deallocate an array!)
	//And then finally update the size to reflect the size of the newly 
	//allocated items array. Make sure to update any pointers as needed.

	//The items variable should ALWAYS point to the array being used to hold shopping cart items,
	//the itemsCount should tell how many items are in that array, 
	//and the itemsArrSize tells the actual number of spaces in the array (occupied or not)

	//TODO: Finish the function
	int addARRnRES=itemsArrSize+RESIZE_AMOUNT;
	//make temp array
	Item** temp = new Item*[addARRnRES];
	for(int i = 0; i<itemCount; i++){
		temp[i]=items[i];//copy elements 
	}
	itemsArrSize+=RESIZE_AMOUNT;
	delete[] items;
	items=temp;

}

//TODO: Write the printCart function definition to print all of the Items in the ShoppingCart
/*
* function_identifier: print cart
* parameters: none
* return value: none
*/
void ShoppingCart::printCart(){
	for(int i = 0 ; i <itemCount ; i++){
		 items[i]->printItemInfo();//use the opperator to call print
	}
 
}


//TODO: Write the getTotalCost function to find the total cost of all the Items in the ShoppingCart
/*
* function_identifier: getting total cost 
* parameters: none
* return value: float
*/
float ShoppingCart::getTotalCost(){
	float totalCost=0;
	for(int i =0;i<itemCount;i++){
	//use opperator to multiply price and quantity 
	totalCost+=items[i]->getPrice()*items[i]->getQuantity();
	}
	return totalCost; 
}

/* */
ShoppingCart::~ShoppingCart()
{
	//Clear out the shopping cart by first deleting all of the items contained within it
	//Then, deallocate the array that held all of those items
	//Remember that there are different deletes for different contexts, make sure you
	//are using he correct version.

	//TODO: Finish the function
	for(int i =0;i<itemCount;i++){
		//delete each thing in array
		delete items[i];//fix this
	}
	delete[] items;
}

// -------------------------- Constructors --------------------------

//Default constructor
ShoppingCart::ShoppingCart()
{
	//This should initialize the shopping cart to be empty by making the items array point to null
	//The count and size should be 0
	items = nullptr;
	itemCount = 0;
	itemsArrSize = 0;
}

//Constructor that initializes the array to a given size
ShoppingCart::ShoppingCart(int initial_size)
{
	//This constructor should construct an empty shopping cart, but allocate an array of the given size
	//Initialize the items array using the size, set the size variable, and initialize count to 0

	items = new Item*[initial_size];
	itemCount = 0;
	itemsArrSize = initial_size;
}





