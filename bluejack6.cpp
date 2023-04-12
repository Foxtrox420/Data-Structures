#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Order{
	char name[50];
	int amount;  
	Order* next; 
}*head = NULL,*tail = NULL;

struct userData{
	char number[50]; 
	char email[50]; 
	char name[50]; 
	int points; 
	int drinks; 
	userData* n; 
}*h = NULL, *t = NULL;

userData* makeUser(char number[], char email[], char name[], int points, int drinks){
	userData* newUser = (userData*)malloc(sizeof(userData)); 
	strcpy(newUser->number, number);
	strcpy(newUser->email, email);
	strcpy(newUser->name, name); 
	newUser->points = points;  
	newUser->drinks = drinks;
	newUser->n = NULL; 
	return newUser; 
}

Order* makeOrder(char name[], int amount){
	Order* newOrder = (Order*)malloc(sizeof(Order)); 
	newOrder->amount = amount;
	strcpy(newOrder->name, name); 
	newOrder->next = NULL; 
	return newOrder; 
}

void pushtailOrder(char name[], int amount){
	Order* newOrder = makeOrder(name, amount); 
	if(head == NULL){
		head = tail = newOrder;
	}
	else{
		tail->next = newOrder; 
		tail = newOrder; 
		tail->next = NULL; 
	}
	return; 
}

void pushtailUser(char number[], char email[], char name[], int points, int drinks){
	userData* newUser = makeUser(number, email, name, points, drinks); 
	if(h == NULL){
		h = t = newUser;
	}
	else{
		t->n = newUser; 
		t = newUser; 
		t->n = NULL; 
	}
	return; 
}


void printMenu(){
	system("cls");   
	printf("BlueBucks\n");
	printf("==================\n"); 
	printf("1. Process Order\n");
	printf("2. View All Customer\n"); 
	printf("3. Remove Customer\n"); 
	printf("4. Exit\n"); 
	printf(">> "); 
}

int comValidation(char email[]){
	int flag = 0; // 18 
	int len, counter = 0, atcount = 0; 
	char temp[10]; 
	len = strlen(email); 
	for(int i = 0; i < len; i++){
		if(email[i] == '.'){
			flag = i; 
		}
		if(email[i] == '@'){
			atcount++;
		}
	}
	if(email[flag+1] == 'c' && email[flag+2] == 'o' && email[flag+3] == 'm' && atcount == 1){
		counter++; 
	}
	if(counter == 1){
		return 1; 
	}
	else{
		return 2; 
	}
}

int coidValidation(char email[]){
	int flag = 0; // 18 
	int len, counter = 0, atcounter = 0; 
	char temp[10]; 
	len = strlen(email); 
	for(int i = 0; i < len; i++){
		if(email[i] == '.'){
			flag = i; 
			break;
		}
		if(email[i] == '@'){
			atcounter++;
		}
	}
	if(email[flag+1] == 'c' && email[flag+2] == 'o' && email[flag+3] == '.' && email[flag+4] == 'i' && email[flag+5] == 'd' && atcounter == 1){
		counter++; 
	}
	if(counter == 1){
		return 1; 
	}
	else{
		return 2; 
	}
}

int nameValidator(char name[]){
	int len; 
	
	len = strlen(name); 
	if(name[0] == 'M' && name[1] == 'r' && name[2] == '.'){
		return 1; 
	}
	else if(name[0] == 'M' && name[1] == 'r' && name[2] == 's' && name[3] == '.'){
		return 1; 
	}
	else{
		return 2; 
	}
	
}

void orderSummary(){
	Order* curr = head; 
	if(head == NULL){
		printf("There is no data!\n");
		printf("Press Enter to continue ...\n"); getchar(); 
	}
	while(curr != NULL){
		printf("%s %dx = %d\n", curr->name, curr->amount, curr->amount*30000);
		curr = curr->next; 
	}
	
}

void printNames(){
	userData* curr = h; 
	if(curr == NULL){
		printf("\nThere is no data!\n");
	}
	else{
		printf("======================================================\n");
		printf("Name        |Phone Number   |    Email    | Points\n");
		printf("======================================================\n");
		while(curr != NULL){
			printf("%s | %s | %s | %d \n", curr->name, curr->number, curr->email, curr->points);
			printf("======================================================\n"); 
			curr = curr->n;
		}	
	}
	return; 
}

int searchUser(char number[]){
	userData* curr = h; 
	while(curr != NULL){
		if(strcmp(curr->number, number) == 0){
			return 1; 
		}
		curr = curr->n; 
	}
	return 2; 
}

void updatePoints(char number[], int points){
	userData* curr = h;
	while(curr != NULL){
		if(strcmp(curr->number, number) == 0){
			curr->points += points*3;  
		}
		curr = curr->n; 
	}
}

void cutPoints(char number[], int points){
	userData* curr = h;
	
	while(curr != NULL){
		if(strcmp(curr->number, number) == 0){ 		  
			printf("\n-OVERVIEW-\n\nCurrent Balance : %d pts  \nPoints Deduction : %d pts\n-----------------------\nUpdated Balance = %d pts\nPress Enter to Verify...", curr->points, points, curr->points - points); getchar(); 
			curr->points = curr->points - points;
		}
		curr = curr->n; 
	}
}

void addDrink(char number[], int drinks){
	userData* curr = h;
	while(curr != NULL){
		if(strcmp(curr->number, number) == 0){
			curr->drinks += drinks;  
		}
		curr = curr->n; 
	}
}


void popcurrOrder(){
	if(head == NULL){
			return; 
		}
		else if(head == tail){
			free(head);
			head = NULL; 
			tail = NULL; 
		}
		else{
			Order* curr = head; 
			while(curr != NULL){
				Order* temp = curr->next;
				free(curr);
				curr = temp; 	
			}
	}
}

int sendback(char number[], int currpoints){
	userData* curr = h; 
	while(curr != NULL){
		if(strcmp(curr->number, number) == 0){
			currpoints = curr->points;  
			return currpoints; 
		}
		curr = curr->n;
	}
}

int retDrinks(char number[], int drinks){
	userData* curr = h; 
	while(curr != NULL){
		if(strcmp(curr->number, number) == 0){
			drinks = curr->drinks;  
			return drinks; 
		}
		curr = curr->n;
	}
}

int main(){
	
	int input, checker = 0, checker2 = 0, overall, overall2; 
	char number[50], name[50], email[50], temp[50], option[2], option2[2], drink[50]; 
	int freedrinks = 0, amount, ordernum = 0;
	int totalprice = 0, temppoints = 0, points = 0, temporary = 0; 
	int validator, currpoints = 0, cutpoints, currdrinks; 
	
	// .com = moc.@ 
	// .co.id = di.oc.@ 
	
	do{
		printMenu(); 
		scanf("%d", &input); 
		switch(input){ 
			case 1 :
				do{
					printf("Input phone number[10-13][numeric]: "); scanf("%s", number); getchar();
//					printf("Stauts : %d\n", searchUser(number)); 
				}while(strlen(number) < 10 || strlen(number) > 13); 
				validator = searchUser(number);
				if(validator == 2){
					do{
						printf("Input name[5-25][Mr. | Mrs.]: "); scanf("%[^\n]", name); getchar(); 
						overall = nameValidator(name); 
					}while(overall == 2 || strlen(name) < 5 || strlen(name) > 25);
					do{
						printf("Input email[10-20][email format]: "); scanf("%s", email); getchar();
						checker = comValidation(email);
						checker2 = coidValidation(email); 
						if(checker == 2 && checker2 == 2){
							overall2 = 0; 
						}
						else if(checker == 1 || checker2 == 1){
							overall2 = 1; 
						} 
					}while(overall2 == 0 || strlen(email) < 10 || strlen(email) > 25); 
			
					printf("Insert Success !\n\n"); 
				}
				
				else if(validator == 1){
					currpoints = sendback(number, currpoints);
					if(currpoints > 25){
						printf("Do you want to use your points[You have %d][y|n]: ", currpoints); scanf("%s", option2); getchar();
						if(strcmp(option2, "y") == 0){
							printf("How much[%d left]: ", currpoints); scanf("%d", &cutpoints); getchar(); 
							if(cutpoints%25 == 0){
								freedrinks = cutpoints/25; 
							}
							cutPoints(number, cutpoints); 
							addDrink(number, freedrinks);
						}
					} 
				}
				
				system("cls"); 
				printf("===============================\n");
				printf("========BLUEBUCKS-ORDERS=======\n");
				printf("===============================\n\n");
				currdrinks = retDrinks(number, freedrinks);
				
				if(currdrinks >= 1){
				
					do{
						printf("\n-You have %d free drink(s) left.-\n\n", currdrinks);
						do{
							printf("Input drink [Cafe Latte | Caramel Macchiato| Cappucino | Cafe Mocha]: "); scanf("%[^\n]", drink); getchar();
						}while(strcmp(drink, "Cafe Latte") != 0 && strcmp(drink, "Caramel Macchiato") != 0 && strcmp(drink, "Cappucino") != 0 && strcmp(drink, "Cafe Mocha") != 0);
						do{
							printf("Input drink quantity[>=1]: "); scanf("%d", &amount); getchar();  
						}while(amount < 1 || amount < currdrinks);
						temporary += amount; 
						pushtailOrder(drink, amount);
						printf("Total redeemed = %d\n", temporary); 
						printf("Do you want to order more? [y|n]: "); scanf("%s", option); getchar(); 
						currdrinks -= temporary;
						//program will only repeat when user press y, the freedrinks havent finished and the amount is still less than the amount of free drinks
					}while(currdrinks > 0); 
				}
				
				printf("\n-You have %d free drink(s) left.-\n\n", currdrinks);
				do{
					do{
						printf("Input drink [Cafe Latte | Caramel Macchiato| Cappucino | Cafe Mocha]: "); scanf("%[^\n]", drink); getchar();
					}while(strcmp(drink, "Cafe Latte") != 0 && strcmp(drink, "Caramel Macchiato") != 0 && strcmp(drink, "Cappucino") != 0 && strcmp(drink, "Cafe Mocha") != 0);
					do{
						printf("Input drink quantity[>=1]: "); scanf("%d", &amount); getchar();  
					}while(amount < 1);
					temporary += amount; 
					pushtailOrder(drink, amount);
					printf("Cart Amount = %d\n", temporary); 
					totalprice += temporary*30000; 
					printf("Do you want to order more? [y|n]: "); scanf("%s", option); getchar(); 
				}while(strcmp(option, "y") == 0); 
				printf("\n=== Order Summary ===\n");
				orderSummary();
				printf("\nTotal : %d\n", totalprice); 
				if(validator == 2){
					printf("Points Obtained : %d\n", totalprice/50000);	
					pushtailUser(number, email, name, totalprice/50000, freedrinks); 	
				}
				else{
					printf("Points Obtained : %d\n", points*3); 
					updatePoints(number, points); 
				}
				printf("=====================\n");
				popcurrOrder(); 
				freedrinks = 0; temporary = 0; points = 0; totalprice = 0; temppoints = 0; amount = 0;
				break; 
			case 2 : 
				printNames(); getchar();  
				break;
			case 3 :
				break; 
		}
		puts("\nPress enter to continue");
		getchar(); 
	}while(input != 4); 
	return 0; 
}

// Things to fix :
// Fix the point calculation system, seems to be bugged a bit, seems like the problem is at the pushing part, instead of stacking the same type of drink, update it in the order summary
// I think this can be done by doing a search if it exists, then updating the cart amount by adding it, but idk. 
// Another bug is when I redeem the free drinks first, then the place a new order, it doesn't add the points. 

// overall points system have to be re-evaluated. 
