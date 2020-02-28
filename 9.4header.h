#define QUIT 5
#define HOTEL1 100.00
#define HOTEL2 225.00
#define HOTEL3 255.00
#define HOTEL4 300.00
#define DISCOUNT 0.95
#define STAR "***********************"


// 显示菜单，并返回操作选项
int menu(void);

// 获取入住天数
int getNights(void);

// 显示入住酒店每天需要支付的金额
void showPrice(double rate, int nights);