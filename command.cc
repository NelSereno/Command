#include <iostream>
#include <list>

class Stock{
	std::string name = "ABC";
	int quantity = 10;
	public:
	void buy(){
	    std::cout << "Stock [ Name: " << name 
	    << ", Quantity: " << quantity << " ] bought"
	    << std::endl;
	};
	void sell(){
	    std::cout << "Stock [ Name: " << name
	    << ", Quantity: " << quantity << " ] sold"
	    << std::endl;
	};
};

class Order{
	public:
	virtual void execute() = 0;
};

class BuyStock: public Order{
	Stock* abcStock;
	public:
	BuyStock(Stock* abcStock){
	    this->abcStock = abcStock;
	};
	void execute() override{
	    abcStock->buy();
	};
};

class SellStock: public Order{
	Stock* abcStock;
	public:
	SellStock(Stock* abcStock){
	    this->abcStock = abcStock;
	};
	void execute() override{
	    abcStock->sell();
	};
};

class Broker{
	std::list<Order*> orderList;
	public:
	void takeOrder(Order* order){
        orderList.push_front(order);
	};
	void placeOrders(){
	    for(Order* order : orderList){
	        order->execute();
	    }
	    orderList.clear();
	};
};

int main(){
    Stock* abcStock = new Stock;
    
    BuyStock* buyStockOrder = new BuyStock(abcStock);
    SellStock* sellStockOrder = new SellStock(abcStock);
    
    Broker* broker = new Broker;
    broker->takeOrder(buyStockOrder);
    broker->takeOrder(sellStockOrder);
    
    broker->placeOrders();
}