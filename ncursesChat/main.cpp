#include <ncurses.h>

void DrawBorder();

int main()
{
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr,TRUE);
	keypad(stdscr,TRUE);

	start_color();
	init_pair(1,COLOR_BLACK,COLOR_BLUE);
	init_pair(2,COLOR_BLACK,COLOR_RED);
	init_pair(3,COLOR_RED,COLOR_WHITE);

	DrawBorder();

	WINDOW* ROOM;
	WINDOW* PEERS;
	WINDOW* INPUT;

	// newwin(rows,cols,y_org,x_org)
	ROOM = newwin(18,59,1,1);
	box(ROOM,'*','*');
	wbkgd(ROOM,COLOR_PAIR(1));
	mvwaddstr(ROOM, 1,1, "Chat box\n");

	PEERS = newwin(18,18,1,60);
	box(PEERS,'*','*');
	wbkgd(PEERS,COLOR_PAIR(2));
	mvwaddstr(PEERS, 1,1, "Peer list:\n");

	INPUT = newwin(4,77,19,1);
	box(INPUT,'*','*');
	wbkgd(INPUT,COLOR_PAIR(3));
	mvwprintw(INPUT,1,1, "Message: ");

	int c;
	c = getch();
	char* input;
	do
	{
		/*touchwin(ROOM);
		touchwin(PEERS);
		*/
		wrefresh(PEERS);
		wrefresh(ROOM);
		wrefresh(INPUT);

		echo();
		//wscanw(INPUT,"%s",input); // Can't get window input to work ATM
		noecho();

		touchwin(INPUT);

		c = getch();

	}
	while(c != KEY_F(1));

	nodelay(stdscr,FALSE);
	getch();
	delwin(ROOM);
	delwin(PEERS);
	delwin(INPUT);
	endwin();

	return 0;
}

void DrawBorder()
{
	clear();
	box(stdscr,'*','*');
}
