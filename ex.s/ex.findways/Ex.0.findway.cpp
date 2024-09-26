#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Window{
    int x,y;
    string caption;
    public:
        Window(int X,int Y,string Caption){
            this->x = X;
            this->y = Y;
            this->caption = Caption;
        }  
        Window(){
            this->x = 500;
            this->y = 800;
            this->caption = "Untitled";
        }
        void BornShell()
        {
            sf::RenderWindow win(sf::VideoMode(this->x,this->y),this->caption,sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
            sf::RectangleShape rect(sf::Vector2f(100,100));
            while(win.isOpen())
            {
                sf::Event ev;
                while(win.pollEvent(ev)){
                    switch(ev.type){
                        case sf::Event::Closed:
                            cout << "closed" << endl;
                            win.close();
                            break;
                        case sf::Event::Resized:
                            //cout << "resized & "<< ev.size.width << " , " << ev.size.height << endl;
                            if(ev.size.width <= 100){
                                ev.size.width = 100;
                            }
                            break;
                        case sf::Event::TextEntered:
                            printf("%c",ev.text.unicode);
                            break;

                    }
                }
                // window ====================
                win.draw(rect);
                win.display();
            }
        }

};

int main(){

    Window win(500,500,"Elt");
    win.BornShell();

    return 0;
}