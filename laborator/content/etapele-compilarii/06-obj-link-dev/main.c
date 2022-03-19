extern qty;

int main(void)
{
	/*
	 * TODO: Make it so you print:
	 *    price is 21
	 *    quantity is 42
	 * without directly calling a printing function from an existing
	 * library(do NOT use printf, fprintf, fwrite, ...).
	 */
	int price;
	price=set_price(21);
	print_price(price);
	qty=2*price;
	print_quantity(&qty);
	return 0;
}
