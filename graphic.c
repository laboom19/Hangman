#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<time.h>

static char *LOSSER_SCREEN = 
	"|===============================================================================================================================================================|\n"
	"|																				|\n"
	"|					 ▄▄·        ▐ ▄  ▄▄ • ▄▄▄   ▄▄▄· ▄▄▄▄▄▄• ▄▌▄▄▌   ▄▄▄· ▄▄▄▄▄▪         ▐ ▄ .▄▄ · 						|\n"
	"|					▐█ ▌▪ ▄█▀▄ •█▌▐█▐█ ▀ ▪▀▄ █·▐█ ▀█ •██  █▪██▌██•  ▐█ ▀█ •██  ██  ▄█▀▄ •█▌▐█▐█ ▀. 						|\n"
	"|					██ ▄▄▐█▌.▐▌▐█▐▐▌▄█ ▀█▄▐▀▀▄ ▄█▀▀█  ▐█.▪█▌▐█▌██ ▪ ▄█▀▀█  ▐█.▪▐█·▐█▌.▐▌▐█▐▐▌▄▀▀▀█▄						|\n"
	"|					▐███▌▐█▌.▐▌██▐█▌▐█▄▪▐█▐█•█▌▐█▪ ▐▌ ▐█▌·▐█▄█▌▐█▌ ▄▐█▪ ▐▌ ▐█▌·▐█▌▐█▌.▐▌██▐█▌▐█▄▪▐█						|\n"
	"|					·▀▀▀  ▀█▄▀▪▀▀ █▪·▀▀▀▀ .▀  ▀ ▀  ▀  ▀▀▀  ▀▀▀ .▀▀▀  ▀  ▀  ▀▀▀ ▀▀▀ ▀█▄▀▪▀▀ █▪ ▀▀▀▀ 						|\n"
	"|																				|\n"
	"|					     ▄▄                                                  ▄▄    ▄▄    ▄▄                 ▄▄            ▄▄ 		|\n"               
	"|					    ███                                      ▀███        ██  ▀███  ▀███               ▀███       ██  ███                |\n"
	"|					    ██                                        ██              ██    ██                 ██       ██   ██                 |\n"
	"|	▀██▀   ▀██▀ ▄██▀██▄▀███  ▀███      ███████▄  ▄█▀██▄ ▀██▀   ▀██▀  ▄▄█▀██      ██  ▄██▀▀███    ██    ██   ▄▄█▀██   ▄█▀▀███     ██████ ███████▄   ▄▄█▀██ 	|\n"
	"|	  ██   ▄█  ██▀   ▀██ ██    ██      ██    ██ ██   ██   ██   ▄█   ▄█▀   ██     ██ ▄█     ██    ██    ██  ▄█▀   ██▄██    ██       ██   ██    ██  ▄█▀   ██	|\n"
	"| 	  ██ ▄█   ██     ██ ██    ██      ██    ██  ▄█████    ██ ▄█    ██▀▀▀▀▀▀     ██▄██     ██    ██    ██  ██▀▀▀▀▀▀███    ██       ██   ██    ██  ██▀▀▀▀▀▀	|\n"
	"| 	  ███    ██▄   ▄██ ██    ██      ██    ██ ██   ██     ███     ██▄    ▄     ██ ▀██▄   ██    ██    ██  ██▄    ▄▀██    ██       ██   ██    ██  ██▄    ▄	|\n"
	"|  	  ▄█      ▀█████▀  ▀████▀███▄   ████  ████▄████▀██▄    █       ▀█████▀   ▄████▄ ██▄▄████▄▄████▄▄████▄ ▀█████▀ ▀████▀███▄     ▀███████  ████▄ ▀█████▀	|\n"
	"|	  ▄█                                                                                                                                                  	|\n"
	"|	██▀                                                                                                                                                   	|\n"
	"|																				|\n"
	"|       																			|\n"
	"|								███▄ ▄███▓ ▄▄▄      ███▄    █ 									|\n"
	"|								▓██▒▀█▀ ██▒▒████▄    ██ ▀█   █ 									|\n"
	"|								▓██    ▓██░▒██  ▀█▄ ▓██  ▀█ ██▒									|\n"
	"|								▒██    ▒██ ░██▄▄▄▄██▓██▒  ▐▌██▒									|\n"
	"|								▒██▒   ░██▒▒▓█   ▓██▒██░   ▓██░									|\n"
	"|								░ ▒░   ░  ░░▒▒   ▓▒█░ ▒░   ▒ ▒ 									|\n"
	"|								░  ░      ░░ ░   ▒▒ ░ ░░   ░ ▒░									|\n"
	"|								░      ░     ░   ▒     ░   ░ ░ 									|\n"
	"|								       ░         ░           ░ 									|\n"
	"|																				|\n"
	"|===============================================================================================================================================================|\n";



static char *WINNER_SCREEN = 
	"|===============================================================================================================================================================|\n"
	"|	                                  	 __              __            __     __                            						|\n"
        "|  	 	                                |  \\            |  \\          |  \\   |  \\                           						|\n"
	"|	  _	__  ______  _______   ______   ______   ______ _| ▓▓_   __    __| ▓▓ ______  _| ▓▓_   \\▓▓ ______  _______   _______ 				|\n"
	"|	 /       \\/      \\|       \\ /      \\ /      \\ |      \\|   ▓▓ \\ |  \\  |  \\ ▓▓|      \\|   ▓▓ \\ |  \\/      \\|       \\ /       \\				|\n"
	"|	|  ▓▓▓▓▓▓▓  ▓▓▓▓▓▓\\ ▓▓▓▓▓▓▓\\  ▓▓▓▓▓▓\\  ▓▓▓▓▓▓\\ \\▓▓▓▓▓▓\\\\▓▓▓▓▓▓ | ▓▓  | ▓▓ ▓▓ \\▓▓▓▓▓▓\\\\▓▓▓▓▓▓ | ▓▓  ▓▓▓▓▓▓\\ ▓▓▓▓▓▓▓\\  ▓▓▓▓▓▓▓				|\n"
	"|	| ▓▓     | ▓▓  | ▓▓ ▓▓  | ▓▓ ▓▓  | ▓▓ ▓▓   \\▓▓/      ▓▓ | ▓▓ __| ▓▓  | ▓▓ ▓▓/      ▓▓ | ▓▓ __| ▓▓ ▓▓  | ▓▓ ▓▓  | ▓▓\\▓▓    \\ 				|\n"
	"|	| ▓▓_____| ▓▓__/ ▓▓ ▓▓  | ▓▓ ▓▓__| ▓▓ ▓▓     |  ▓▓▓▓▓▓▓ | ▓▓|  \\ ▓▓__/ ▓▓ ▓▓  ▓▓▓▓▓▓▓ | ▓▓|  \\ ▓▓ ▓▓__/ ▓▓ ▓▓  | ▓▓_\\▓▓▓▓▓▓\\				|\n"
	"| 	 \\▓▓     \\\\▓▓    ▓▓ ▓▓  | ▓▓\\▓▓    ▓▓ ▓▓      \\▓▓    ▓▓  \\▓▓  ▓▓\\▓▓    ▓▓ ▓▓\\▓▓    ▓▓  \\▓▓  ▓▓ ▓▓\\▓▓    ▓▓ ▓▓  | ▓▓       ▓▓				|\n"
	"| 	  \\▓▓▓▓▓▓▓ \\▓▓▓▓▓▓ \\▓▓   \\▓▓_\\▓▓▓▓▓▓▓\\▓▓       \\▓▓▓▓▓▓▓   \\▓▓▓▓  \\▓▓▓▓▓▓ \\▓▓ \\▓▓▓▓▓▓▓   \\▓▓▓▓ \\▓▓ \\▓▓▓▓▓▓ \\▓▓   \\▓▓\\▓▓▓▓▓▓▓ 				|\n"
	"|   	   	                  |  \\__| ▓▓                                                                                       				|\n"
 	"|             	             	   \\▓▓    ▓▓                                                                                       				|\n"
 	"|                          	    \\▓▓▓▓▓▓															|\n"
	"|																				|\n"
	"|			██╗   ██╗ ██████╗ ██╗   ██╗    ███████╗ █████╗ ██╗   ██╗███████╗██████╗     ████████╗██╗  ██╗███████╗					|\n"
	"|			╚██╗ ██╔╝██╔═══██╗██║   ██║    ██╔════╝██╔══██╗██║   ██║██╔════╝██╔══██╗    ╚══██╔══╝██║  ██║██╔════╝					|\n"
	"|			╚████╔╝ ██║   ██║██║   ██║    ███████╗███████║██║   ██║█████╗  ██║  ██║       ██║   ███████║█████╗					|\n"
	"|			  ╚██╔╝  ██║   ██║██║   ██║    ╚════██║██╔══██║╚██╗ ██╔╝██╔══╝  ██║  ██║       ██║   ██╔══██║██╔══╝					|\n"
	"|			   ██║   ╚██████╔╝╚██████╔╝    ███████║██║  ██║ ╚████╔╝ ███████╗██████╔╝       ██║   ██║  ██║███████╗					|\n"
	"|			   ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝╚═╝  ╚═╝  ╚═══╝  ╚══════╝╚═════╝        ╚═╝   ╚═╝  ╚═╝╚══════╝					|\n"
	"|																				|\n"
	"|							 ______ ____   ______  _______										|\n"
	"|							|      \\    \\ |      \\|       \\										|\n"
	"|							| ▓▓▓▓▓▓\\▓▓▓▓\\ \\▓▓▓▓▓▓\\ ▓▓▓▓▓▓▓\\									|\n"
	"|							| ▓▓ | ▓▓ | ▓▓/      ▓▓ ▓▓  | ▓▓									|\n"
	"|							| ▓▓ | ▓▓ | ▓▓  ▓▓▓▓▓▓▓ ▓▓  | ▓▓									|\n"
	"|							| ▓▓ | ▓▓ | ▓▓\\▓▓    ▓▓ ▓▓  | ▓▓									|\n"
	"|							 \\▓▓  \\▓▓  \\▓▓ \\▓▓▓▓▓▓▓\\▓▓   \\▓▓									|\n"
	"|																				|\n"
	"|																				|\n"
	"|																				|\n"
	"|===============================================================================================================================================================|\n";
 
 
static char *s[8] ={
/*0*/
	"|_|________..________								\n"
	"| |__________))______|								\n"
	"| | / /      ||								\n"
	"| |/ /       ||								\n"
	"| | /        ||								\n"
	"| |/         ||								\n"
	"| |         ||||  				\n"
	"| |         ||||							\n"
	"| |          ||								\n"
	"| |              								\n"
	"| |              								\n"
	"| |               								\n"
	"| |                							\n"
	"| |          								\n"
	"| |           									\n"
	"| |           									\n"
	"| |           									\n"
	"| |          									\n"
	"| |=====================|							\n"
	"|=|===================|=|							\n"
	"| |                   | |							\n"
	"| |                   | |							\n"
	"| |                   | |							\n",

/*1*/	
	"|_|________..________								\n"
	"| |__________))______|								\n"
	"| | / /      ||								\n"
	"| |/ /       ||								\n"
	"| | /        .-''.								\n"
	"| |/        /_  _ \\								\n"
	"| |         |o  o |   ...hello				\n"
	"| |         \\\\ o /								\n"
	"| |         .-===.								\n"
	"| |              								\n"
	"| |              								\n"
	"| |               								\n"
	"| |                							\n"
	"| |          								\n"
	"| |           									\n"
	"| |           									\n"
	"| |           									\n"
	"| |          									\n"
	"| |=====================|							\n"
	"|=|===================|=|							\n"
	"| |                   | |							\n"
	"| |                   | |							\n"
	"| |                   | |							\n",

/*2*/	"|_|________..________								\n"
	"| |__________))______|								\n"
	"| | / /      ||								\n"
	"| |/ /       ||								\n"
	"| | /        .-''.								\n"
	"| |/        /_  _ \\								\n"
	"| |         |0  0 |   ...				\n"
	"| |         \\\\ = /								\n"
	"| |         .-===.								\n"
	"| |         Y     Y								\n"
	"| |              								\n"
	"| |               								\n"
	"| |                							\n"
	"| |          								\n"
	"| |           									\n"
	"| |           									\n"
	"| |           									\n"
	"| |          									\n"
	"| |=====================|							\n"
	"|=|===================|=|							\n"
	"| |                   | |							\n"
	"| |                   | |							\n"
	"| |                   | |							\n",

/*3*/	"|_|________..________								\n"
	"| |__________))______|								\n"
	"| | / /      ||								\n"
	"| |/ /       ||								\n"
	"| | /        .-''.								\n"
	"| |/        /_  _ \\								\n"
	"| |         |0  0 |   .....ky kr rahahy bhai...				\n"
	"| |         \\\\ o /								\n"
	"| |         .-===.								\n"
	"| |         Y     Y								\n"
	"| |          |   | 								\n"
	"| |          |   |  								\n"
	"| |          |   |   							\n"
	"| |          .....								\n"
	"| |           									\n"
	"| |           									\n"
	"| |           									\n"
	"| |          									\n"
	"| |=====================|							\n"
	"|=|===================|=|							\n"
	"| |                   | |							\n"
	"| |                   | |							\n"
	"| |                   | |							\n",

/*4*/	"|_|________..________								\n"
	"| |__________))______|								\n"
	"| | / /      ||								\n"
	"| |/ /       ||								\n"
	"| | /        .-''.								\n"
	"| |/        /_  _ \\								\n"
	"| |         |0  0 |   ......				\n"
	"| |         \\\\ = /								\n"
	"| |         .-===.								\n"
	"| |        /Y     Y								\n"
	"| |       // |   | 								\n"
	"| |      //  |   |  								\n"
	"| |     ')   |   |   							\n"
	"| |          .....								\n"
	"| |           									\n"
	"| |           									\n"
	"| |           									\n"
	"| |          									\n"
	"| |=====================|							\n"
	"|=|===================|=|							\n"
	"| |                   | |							\n"
	"| |                   | |							\n"
	"| |                   | |							\n",

/*5*/	
	"|_|________..________								\n"
	"| |__________))______|								\n"
	"| | / /      ||								\n"
	"| |/ /       ||								\n"
	"| | /        .-''.								\n"
	"| |/        /_  _ \\								\n"
	"| |         |0  0 | ..aab to bhagwan he bachai muje				\n"
	"| |         \\\\ o /								\n"
	"| |         .-===.								\n"
	"| |        /Y     Y\\								\n"
	"| |       // |   | \\\\								\n"
	"| |      //  |   |  \\\\								\n"
	"| |     ')   |   |   (`							\n"
	"| |          .....								\n"
	"| |           									\n"
	"| |           									\n"
	"| |           									\n"
	"| |          									\n"
	"| |=====================|							\n"
	"|=|===================|=|							\n"
	"| |                   | |							\n"
	"| |                   | |							\n"
	"| |                   | |							\n",

/*6*/	
	"|_|________..________								\n"
	"| |__________))______|								\n"
	"| | / /      ||								\n"
	"| |/ /       ||								\n"
	"| | /        .-''.								\n"
	"| |/        /_  _ \\								\n"
	"| |         |0  0 | ..jai hanuman gun sagar jai kapis tihun log ujagar		\n"
	"| |         \\\\ o /								\n"
	"| |         .-===.								\n"
	"| |        /Y     Y\\								\n"
	"| |       // |   | \\\\								\n"
	"| |      //  |   |  \\\\								\n"
	"| |     ')   |   |   (`							\n"
	"| |          ||-								\n"
	"| |          || 								\n"
	"| |          || 								\n"
	"| |          || 								\n"
	"| |         / | 								\n"
	"| |=====================|							\n"
	"|=|===================|=|							\n"
	"| |                   | |							\n"
	"| |                   | |							\n"
	"| |                   | |							\n",

/*7*/	"|_|__________.._______						\n"
	"| .__________))______|						\n"
	"| | / /      ||						\n"
	"| |/ /       ||						\n"
	"| | /        ||.-''.						\n"
	"| |/         |/  _  \\						\n"
	"| |          ||  x/x| ....uuwaaaa....				\n"
	"| |          (\\\\`_.'						\n"
	"| |         .-`--'.						\n"
	"| |        /Y     Y\\						\n"
	"| |       // |   | \\\\						\n"
	"| |      //  |   |  \\\\						\n"
	"| |     ')   |   |   (`					\n"
	"| |          ||-||						\n"
	"| |          || ||		...OM shanti...OM shanti	\n"
	"| |          || ||			  _.-._			\n"	
	"| |          || ||			/| | | |_		\n"
	"| |         / | | \\			|| | | | |		\n"
	"==========|_`-' `-' |===|		|| | | | |		\n"
	"|=|=======\\ \\       '=|=|	       _||     ` |		\n"
	"| |        \\ \\        | |	      \\\\`\\       ;		\n"
	"| |         \\ \\       | |  	       \\\\        |		\n"
	"| |	      --      | |		\\\\      /		\n"
	"| |   		      | |		 ||	|		\n",

};



static char *WELCOME_SCREEN =
	"||=========================================================================================================================||\n"
        "||					              	 __						    		   ||\n"
	"||  ||==========,====			.--.--.--.-----.|  |.----.-----.--------.-----.			====,==========||  ||\n"
	"||  ||	/	 |    			|  |  |  |  -__||  ||  __|  _  |        |  -__|			    | 	     \\ ||  ||\n"
	"||  ||					|________|_____||__||____|_____|__|__|__|_____|			   ()  	       ||  ||\n"
	"||  ||													   /|\\         ||  ||\n"
	"||  ||			       	     			|  |_.-----.					    | 	       ||  ||\n"
	"||  ||		            				|   _|  _  |                                       / \\         ||  ||\n"
	"||  ||							|____|_____|					               ||  ||\n"
	"||  ||													               ||  ||\n"
	"||  ||===============	|  |--.---.-.-----.-----.--------.---.-.-----.    .-----.---.-.--------.-----.	               ||  ||\n"
	"||  ||===============	|     |  _  |     |  _  |        |  _  |     |    |  _  |  _  |        |  -__|	===============||  ||\n"
	"||			|__|__|___._|__|__|___  |__|__|__|___._|__|__|    |___  |___._|__|__|__|_____| 	===============||  ||\n"
       	"||				          |_____|                         |_____|                             		   ||\n"
	"||========================================================================================================================||\n";
static char *LOAD_SCREEN[2] = {	
	"LOADING:", "##########################",
};

void graphic(int wrong, int correct)
{
	if (wrong > 0 && wrong < 8)
		printf("%s\n", s[wrong]);
	else
		printf("%s\n", s[wrong]);
}
void load_screen()
{	
	int i = 0;	
       	printf("%s\n", WELCOME_SCREEN);
	printf("%s ", LOAD_SCREEN[0]);
	while(i < 4)
	{
		fflush(stdout);
		printf("%s", LOAD_SCREEN[1]);
		i++;
		sleep(1);
		fflush(stdout);
	}
}

void winner_screen(){
	printf("%s\n", WINNER_SCREEN);
}

void losser_screen()
{
	printf("%s\n", LOSSER_SCREEN);
}

