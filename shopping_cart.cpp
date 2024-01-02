
#include "shopping_cart.h"

void ShoppingCart::addItem(Item* item)
{

	if(itemCount==itemsArrSize){
	resizeArray();//call the resizeArray
	}

	items[itemCount]=item;//MAYBE CHANGE TO ITEM COUNT
	itemCount++;
}

void ShoppingCart::resizeArray()
{
	
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


void ShoppingCart::printCart(){
	for(int i = 0 ; i <itemCount ; i++){
		 items[i]->printItemInfo();//use the opperator to call print
	}
 
}


float ShoppingCart::getTotalCost(){
	float totalCost=0;
	for(int i =0;i<itemCount;i++){
	 
	totalCost+=items[i]->getPrice()*items[i]->getQuantity();
	}
	return totalCost; 
}

/* */
ShoppingCart::~ShoppingCart()
{
	for(int i =0;i<itemCount;i++){
		//delete each thing in array
		delete items[i];//fix this
	}
	delete[] items;
}




ShoppingCart::ShoppingCart()
{
	
	items = nullptr;
	itemCount = 0;
	itemsArrSize = 0;
}


ShoppingCart::ShoppingCart(int initial_size)
{
	
	items = new Item*[initial_size];
	itemCount = 0;
	itemsArrSize = initial_size;
}





