#include "Platform.h"
#include "config.h"
#include "graphics.h"
#include "bar.h"
#include "searchBar.cpp"
#include <stdio.h>
#include <iostream>
#include "Movie.h"
#include "ClearFiltersButton.cpp"
#include <algorithm>





bool introState;
bool menuState;
bool previewMovieState;
bool filterState;
bool areYouSureYouWantToExitState;
bool typeMode;
bool searchState;
searchBar menuSearchBar;
bool typing;
bool typingTitle;
bool typingActor;
bool typingDirector;
bool typingYear;
bool foundMovie;
graphics::Brush searchText;
std::string searchBarText;
searchBar actorSearchBar;
searchBar directorSearchBar;
searchBar yearSearchBar;
ClearFiltersButton clearFiltersButton;
Movie movieToPreview;
std::string genreToPresent;


Movie fightClub = Movie("Fight Club", "2000", "David Fincher",
	"Edward Norton Brad Pitt", "Action",
	"An introverted every day worker starts off his day rather weirdly when he meets a special some one on the plane.",
	std::string(ASSET_PATH) + "fightClubSoap.png");
Movie theGodfather = Movie("The Godfather", "1972", "Francis Ford Coppola", "Marlon Brando Al Pacino James Caan","Crime", "The aging patriarch of an organized crime dynasty in New York City transfers control of his clandestine empire to his reluctant youngest son.",
	std::string(ASSET_PATH) + "theGodFather.png");
Movie theBigLebowski = Movie("The Big Lebowski", "1998", "Joel Coen", "Jeff Bridges John Goodman Julianne Moore", "Comedy",
	"Ultimate L.A slacker Jeff 'The Dude' or 'El Duderino' Lebowski,mistaken for a millionaire of the same name, seeks restitution for a rug ruined by debt collectors , enlisting his bowling buddies for help while trying to find the millionaire's wife.",
	std::string(ASSET_PATH) + "elDuderino.png");
Movie inception = Movie("Inception", "2010", "Christopher Nolan", "Leonardo DiCaprio Joseph Gordon Levitt Elliot Page", "Thriller",
	"A thief who steals corporate sercrets through the use of dream sharing technology is given the inverse task of planting an idea into the mind of a CEO , but his tragic past may doom the project and his team to disaster.",
	std::string(ASSET_PATH) + "inception.png");
Movie theShining = Movie("The Shining", "1980", "Stanley Kubrick", "Jack Nicholson Shelley Duvall Danny Lloyd", "Horror",
	"A family heads to an isolated hotel for the winter where a sinister presence influences the father into violence , while his psychic son sees horrific forebodings from bost past and future.",
	std::string(ASSET_PATH) + "theShining.png");
Movie forrestGump = Movie("Forrest Gump", "1994", "Robert Zemeckis", "Tom Hanks Robin Wright Gary Sinise", "Drama",
	"The presidencies of Kennedy and Johnson , the Vietnam War, the Watergate scandal and other historical events unfold from the perspective of an Alabama man with an IQ of 75, whose only desire is to be reunited with his childhood sweetheart.",
	std::string(ASSET_PATH) + "forrestGump.png");
Movie starWars = Movie("Star Wars Episode V The Empire Strikes Back", "1980", "Irvin Kershner", "Mark Hamill Harrison Ford Carrie Fisher", "SciFi",
	"After the Rebels are brutally overpowered by the Empire on the ice planet Hoth,Luke Skywalker begins Jedi training with Yoda, while his friends are pursued across the galaxy by Darth Vader and bounty hunter Boba Fett",
	std::string(ASSET_PATH) + "starWars.png");

Movie movies[] = {fightClub,theGodfather,theBigLebowski,inception,theShining,forrestGump,starWars};


int isSubstring(std::string s1, std::string s2)
{
	int M = s1.length();
	int N = s2.length();

	/* A loop to slide pat[] one
	   by one */
	for (int i = 0; i <= N - M; i++)
	{
		int j;

		/* For current index i, check for
		   pattern match */
		for (j = 0; j < M; j++)
			if (s2[i + j] != s1[j])
				break;

		if (j == M)
			return i;
	}
	return -1;
}
char convertScancode(int i) {
	switch (i) {

	case 4:
		return 'A';
	case 5:
		return 'B';
	case 6:
		return 'C';
	case 7:
		return 'D';
	case 8:
		return 'E';//E
	case 9:
		return 'F';//F
	case 10:
		return 'G';//G
	case 11:
		return 'H';//H
	case 12:
		return 'I';//I
	case 13:
		return 'J';//J
	case 14:
		return 'K';//K
	case 15:
		return 'L';//L
	case 16:
		return 'M';//M
	case 17:
		return 'N';//N
	case 18:
		return 'O';//O
	case 19:
		return 'P';//P
	case 20:
		return 'Q';//Q
	case 21:
		return 'R';//R
	case 22:
		return 'S';//S
	case 23:
		return 'T';//T
	case 24:
		return 'U';//U
	case 25:
		return 'V';//V
	case 26:
		return 'W';//W
	case 27:
		return 'X';//X
	case 28:
		return 'Y';//Y
	case 29:
		return 'Z';//Z
	case 30:
		return '1';//1
	case 31:
		return '2';//2
	case 32:
		return '3';//3
	case 33:
		return '4';//4
	case 34:
		return '5';//5
	case 35:
		return '6';//6
	case 36:
		return '7';//7
	case 37:
		return '8';//8
	case 38:
		return '9';//9
	case 39:
		return '0';//0
	case 42:
		searchBarText.pop_back();//BACKSPACE
	case 44:
		return ' ';//SPACE

	return ' ';
	}
}

void Platform::update() {
	// within update() we update boolean values to represent current states such as intro , menu , filter ( search state ) , and a preview state.
	if (introState) {
		// introState is initialized in init() before startMessageLoop()
		// updating the current situation from intro to menu state when a left click is given
		graphics::MouseState ms;
		graphics::getMouseState(ms);
		bool clickToContinue = ms.button_left_down;
		if (graphics::getGlobalTime() > 1000.0f && clickToContinue) {
			introState = false;
			menuState = true;
		}
	}
	if (menuState) {

		graphics::MouseState ms;
		graphics::getMouseState(ms);
		float mouse_y = graphics::windowToCanvasY(ms.cur_pos_y);
		float mouse_x = graphics::windowToCanvasX(ms.cur_pos_x);
		bool leftMouseClick = ms.button_left_down;
		// if mouse is within search bar dimensions and clicks on it than type into search bar
		if (mouse_x > 300 && mouse_x < 900 && mouse_y > 150 && mouse_y < 220 && leftMouseClick) {
			filterState = true;
		}
		// if filter is pressed then remove text from search and draw another rectangle for search bar
		if (mouse_x >= 160  && mouse_x <= 240 && mouse_y >= 75 && mouse_y <= 155 && leftMouseClick) {
			searchBarText = "";
			menuSearchBar.drawBar();
		}
	}
	if (filterState) {
		// if in search state remove on display movies so we can show movies that are being searched
		// hover mechanics for bars and buttons
		graphics::MouseState m;
		graphics::getMouseState(m);
		float x = graphics::windowToCanvasX(m.cur_pos_x);
		float y = graphics::windowToCanvasY(m.cur_pos_y);
		
		
		bool leftMouseClick = m.button_left_down;
		
		if (x >= 25 && x <= 75 && y >= 167.7 && y <= 192.5 && leftMouseClick) {
			movieToPreview = starWars;
			filterState = false;
			menuState = false;
			previewMovieState = true;
		}
		if (x >= 95 && x <= 145 && y >= 167.7 && y <= 192.5 && leftMouseClick) {
			movieToPreview = theBigLebowski;
			filterState = false;
			menuState = false;
			previewMovieState = true;
		}
		if (x >= 165 && x <= 215 && y >= 167.7 && y <= 192.5 && leftMouseClick) {
			movieToPreview = forrestGump;
			filterState = false;
			menuState = false;
			previewMovieState = true;
		}
		if (x >= 25 && x <= 75 && y >= 207.5 && y <= 232.5 && leftMouseClick) {
			movieToPreview = fightClub;
			filterState = false;
			menuState = false;
			previewMovieState = true;
		}
		if (x >= 95 && x <= 145 && y >= 207.5 && y <= 232.5 && leftMouseClick) {
			movieToPreview = theGodfather;
			filterState = false;
			menuState = false;
			previewMovieState = true;
		}
		if (x >= 165 && x <= 215 && y >= 207.5 && y <= 232.5 && leftMouseClick) {
			movieToPreview = inception;
			filterState = false;
			menuState = false;
			previewMovieState = true;
		}
		if (x >= 95 && x <= 145 && y >= 247.5 && y <= 272.5 && leftMouseClick) {
			movieToPreview = theShining;
			filterState = false;
			menuState = false;
			previewMovieState = true;
		}

		if (x >= 260 && x <= 760 && y >= 160
			&& y <= 190) {
			
			if (leftMouseClick) {
				typing = true;
				typingActor = false;
				typingDirector = false;
				typingYear = false;
			}
		}
		if (x >= 440 && x <= 760 && y >= 210 && y <= 240) {
			
			if (leftMouseClick) {
				typingActor = true;
				typing = false;
				typingDirector = false;
				typingYear = false;
			}
		}
		if (x >= 440 && x <= 760 && y >= 250 && y <= 290) {
			
			if (leftMouseClick) {
				typingDirector = true;
				typing = false;
				typingActor = false;
				typingYear = false;
			}
		}
		if (x >= 440 && x <= 760 && y >= 300 && y <= 340) {
			if (leftMouseClick) {
				typingYear = true;
				typing = false;
				typingActor = false;
				typingDirector = false;
			}
		}

		//when enter is hit
		if (graphics::getKeyState(graphics::SCANCODE_RETURN)) {
			// gather movies to display here 

			for (int i = 0; i < sizeof(movies)/sizeof(movies[0]); i++) {
				std::string temp = movies[i].getName();
				std::string tempDirs = movies[i].getDirectors();
				std::string tempStars = movies[i].getStarring();
				std::string tempYears = movies[i].getYear();

				std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
				std::transform(tempStars.begin(), tempStars.end(), tempStars.begin(), ::toupper);
				std::transform(tempDirs.begin(), tempDirs.end(), tempDirs.begin(), ::toupper);
				std::transform(tempYears.begin(), tempYears.end(), tempYears.begin(), ::toupper);
				
				
				int res;
				if (typing) {
					res = isSubstring(searchBarText, temp);
				}

				if (typingActor) {
					res = isSubstring(searchBarText, tempStars);
				}
				if (typingDirector) {
					res = isSubstring(searchBarText, tempDirs);
				}
				if (typingYear) {
					res = isSubstring(searchBarText, tempYears);
				}

				
				if (res != -1) {
					// Display the first movie found 
					movieToPreview = movies[i];	
				}
			}
			// change to preview movie state
			filterState = false;
			previewMovieState = true;
		}
	}
	if (previewMovieState) {
		
		graphics::MouseState ms;
		graphics::getMouseState(ms);
		float x = graphics::windowToCanvasX(ms.cur_pos_x);
		float y = graphics::windowToCanvasY(ms.cur_pos_y);
		bool leftMouseClick = ms.button_left_down;

		// if back button is clicked

		if (x >= 112.5 && x <= 187.5 && y >= 77.5 && y <= 152.5) {
			if (leftMouseClick) {
				previewMovieState = false;
				menuState = true;
			}
		}
	}
}

void Platform::draw() 
{
	if (introState) {
		// draw background
		graphics::Brush br;
		br.texture = std::string(ASSET_PATH) + "movietheater.png";
		br.outline_opacity = 0;
		graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);


		// draw welcome message fading in with 0.15s intervals
		if (graphics::getGlobalTime() > 0.0f) {
			graphics::Brush br;
			br.fill_color[0] = 0.1f;
			br.fill_color[1] = 0.1f;
			br.fill_color[2] = 0.1f;
			graphics::drawText(275, 100, 40, "Welcome to StreamLand", br);
		}
		if (graphics::getGlobalTime() > 150.0f) {
			graphics::Brush br;
			br.fill_color[0] = 0.35f;
			br.fill_color[1] = 0.35f;
			br.fill_color[2] = 0.35f;
			graphics::drawText(275, 100, 40, "Welcome to StreamLand", br);
		}
		if (graphics::getGlobalTime() > 300.0f) {
			graphics::Brush br;
			br.fill_color[0] = 0.6f;
			br.fill_color[1] = 0.6f;
			br.fill_color[2] = 0.6f;
			graphics::drawText(275, 100, 40, "Welcome to StreamLand", br);
		}
		if (graphics::getGlobalTime() > 450.0f) {
			graphics::Brush br;
			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;
			graphics::drawText(275, 100, 40, "Welcome to StreamLand", br);

		}



		// pop up message to click left mouse to continue , fade in interval 0.15 s
		if (graphics::getGlobalTime() > 500.0f) {
			graphics::Brush br;
			br.fill_color[0] = 0.1f;
			br.fill_color[1] = 0.1f;
			br.fill_color[2] = 0.1f;
			graphics::drawText(400, 250, 15, "Press left click to continue.", br);
		}
		if (graphics::getGlobalTime() > 650.0f) {
			graphics::Brush br;
			br.fill_color[0] = 0.35f;
			br.fill_color[1] = 0.35f;
			br.fill_color[2] = 0.35f;
			graphics::drawText(400, 250, 15, "Press left click to continue.", br);
		}
		if (graphics::getGlobalTime() > 800.0f) {
			graphics::Brush br;
			br.fill_color[0] = 0.6f;
			br.fill_color[1] = 0.6f;
			br.fill_color[2] = 0.6f;
			graphics::drawText(400, 250, 15, "Press left click to continue.", br);
		}
		if (graphics::getGlobalTime() > 1000.0f) {
			graphics::Brush br;
			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;
			graphics::drawText(400, 250, 15, "Press left click to continue.", br);
		}

	}
	if (menuState) {
		// immediate black screen then widgets will pop up
		graphics::Brush br;
		br.texture = "";
		graphics::setFont(std::string(ASSET_PATH) + "OpenSans-Regular.ttf");


		// draw main menu background
		br.fill_color[0] = 0.1f;
		br.fill_color[1] = 0.1f;
		br.fill_color[2] = 0.1f;
		br.outline_opacity = 0.0f;
		graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
		// fade in streamland title with new Font (OpenSans)
		if (graphics::getGlobalTime() > 1500.0f) {
			graphics::Brush br;
			br.fill_color[0] = 0.2f;
			br.fill_color[1] = 0.2f;
			br.fill_color[2] = 0.2f;
			br.outline_opacity = 0.0f;
			graphics::drawText(420, 105, 35, "StreamLand", br);
		}
		if (graphics::getGlobalTime() > 1550.0f) {
			graphics::Brush br;
			br.fill_color[0] = 0.4f;
			br.fill_color[1] = 0.4f;
			br.fill_color[2] = 0.4f;
			br.outline_opacity = 0.0f;
			graphics::drawText(420, 105, 35, "StreamLand", br);
		}
		if (graphics::getGlobalTime() > 1600.0f) {
			graphics::Brush br;
			br.fill_color[0] = 0.6f;
			br.fill_color[1] = 0.6f;
			br.fill_color[2] = 0.6f;
			br.outline_opacity = 0.0f;
			graphics::drawText(420, 105, 35, "StreamLand", br);
		}
		if (graphics::getGlobalTime() > 1650.0f) {
			graphics::Brush br;
			br.fill_color[0] = 0.9f;
			br.fill_color[1] = 0.9f;
			br.fill_color[2] = 0.9f;
			br.outline_opacity = 0.0f;
			graphics::drawText(420, 105, 35, "StreamLand", br);
		}
		
		// search bar and lens
		if (graphics::getGlobalTime() > 1650.0f) {
			graphics::Brush br;
			br.texture = std::string(ASSET_PATH) + "fakoss.png";
			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f; 
			br.fill_color[2] = 1.0f;
			br.outline_opacity = 0.0f;
			graphics::drawRect(800, 175, 50, 50, br);
		}

		// draw movie thumbnails
		if (graphics::getGlobalTime() > 1650.0f) {
			
			fightClub.draw(); // starting x_coords = 150 
			forrestGump.draw(270);					// += 100 each time
			theShining.draw(390);
			theBigLebowski.draw(510);
			inception.draw(630);
			theGodfather.draw(750);
			starWars.draw(870);
		}

		if (graphics::getGlobalTime() > 1650.0f) {
			menuSearchBar.drawBar();
		}

		if (typing) {
			graphics::drawText(290, 180, 12, searchBarText, searchText);
		}

		if (typingActor) {
			graphics::drawText(CANVAS_WIDTH / 2, 235, 12, searchBarText, searchText);
		}
		
		if (typingDirector) {
			graphics::drawText(CANVAS_WIDTH / 2, 285, 12, searchBarText, searchText);
		}
		if (typingYear) {
			graphics::drawText(CANVAS_WIDTH / 2, 325, 12, searchBarText, searchText);
		}

	}
	if (filterState) {
		// draw genre buttons
		graphics::Brush ba;
		ba.fill_color[0] = 0.0f;
		ba.fill_color[1] = 0.0f;
		ba.fill_color[2] = 0.0f;
		ba.outline_opacity = 1.0f;


		graphics::drawRect(50, 180, 50, 25, ba);
		graphics::drawRect(120, 180, 50, 25, ba);
		graphics::drawRect(190, 180, 50, 25, ba);
		graphics::drawRect(50, 220, 50, 25, ba);
		graphics::drawRect(120, 220, 50, 25, ba);
		graphics::drawRect(190, 220, 50, 25, ba);
		graphics::drawRect(120, 260, 50, 25, ba);

		//draw button text
		graphics::Brush txtBrush;
		txtBrush.fill_color[0] = 1.0f;
		txtBrush.fill_color[1] = 1.0f;
		txtBrush.fill_color[2] = 1.0f;
		graphics::drawText(40, 180, 12, "SciFi", txtBrush);
		graphics::drawText(100, 180, 12, "Comedy", txtBrush);
		graphics::drawText(175, 180, 12, "Drama", txtBrush);
		graphics::drawText(30, 220, 12, "Action", txtBrush);
		graphics::drawText(105, 220, 12, "Crime", txtBrush);
		graphics::drawText(170, 220, 12, "Thriller", txtBrush);
		graphics::drawText(100, 260, 12, "Horror", txtBrush);

		// paint over menu thumbnails
		graphics::Brush removeThumbnails;
		removeThumbnails.fill_color[0] = 0.1f;
		removeThumbnails.fill_color[1] = 0.1f;
		removeThumbnails.fill_color[2] = 0.1f;
		removeThumbnails.outline_opacity = 0.0f;
		graphics::drawRect(CANVAS_WIDTH / 2, 500, CANVAS_WIDTH, 320, removeThumbnails);

		// draw Text and each respective search bar
		if (graphics::getGlobalTime() > 1000.0f) {
			graphics::Brush br;
			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;
			br.outline_opacity = 0.0f;
			graphics::drawText(660, 150, 15, "Search by Title :", br);

			clearFiltersButton.draw();
			graphics::drawText(150, 75, 10, "Press here to remove search", br);

			actorSearchBar.drawActorBar();
			graphics::drawText(260, 225, 15, "Search by Actors :", br);
			directorSearchBar.drawDirectorsBar();
			graphics::drawText(260, 275, 15, "Search by Director/s :", br);
			yearSearchBar.drawYearBar();
			graphics::drawText(260, 325, 15, "Type in Year :", br);
		}
		// accepting keystrokes to search
		static float delay = 0.0f;
		static int prev = 0;


		searchText.fill_color[0] = 0.0f;
		searchText.fill_color[1] = 0.0f;
		searchText.fill_color[2] = 0.0f;
		searchText.outline_opacity = 0.0f;
		
		delay += graphics::getDeltaTime();
		char myChar;

		// from A - Space we convert the input given , char by char , so we can see if it matches the proper search criteria ( Year , title , director ,starring)
		for (int i = graphics::SCANCODE_A; i <= graphics::SCANCODE_SPACE;
			i++) {
			if (graphics::getKeyState((graphics::scancode_t)i)) {
				if (prev == i && delay < 200.0f) {
					continue;
				}
				else {
					prev = i;
					delay = 0.0f;
				}
				if (prev == graphics::SCANCODE_BACKSPACE) {
					if (searchBarText.size() == 0) {
						continue;
					}
			
				}
				myChar = convertScancode(prev);
				searchBarText.push_back(myChar);
			}
		}		
	}
	if (previewMovieState) {
		// removing search criteria and display the movie found
		searchBarText = "";
		graphics::Brush br;
		br.fill_color[0] = 0.15f;
		br.fill_color[1] = 0.15f;
		br.fill_color[2] = 0.15f;
		br.outline_opacity = 0.0f;
		graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

		br.texture = std::string(ASSET_PATH) + "backButton.png";
		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 1.0f;
		br.outline_opacity = 0.0f;
		graphics::drawRect(150, 115, 75, 75, br);
		
		movieToPreview.previewMovie();
		
	}
}

void Platform::init() {
	introState = true;
	graphics::setFont(std::string(ASSET_PATH) + "font1.ttf");
}


Platform::Platform() {
	// initializing our boolean states 
	introState = true;
	menuState = false;
	previewMovieState = false;
	filterState = false;
	searchState = false;
	areYouSureYouWantToExitState = false;
}

Platform::~Platform() {}

bool Platform::getTypeMode() {
	return typeMode;
}

