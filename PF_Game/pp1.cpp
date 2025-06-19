#include "SFML\Graphics.hpp"
#include<iostream>
#include <cstdlib>
#include <sstream>

using namespace std;
using namespace sf;

bool flag = true;
int s = 0;
int i = 1;
int level = 1;
bool bag = true;

const int window_width = 1366;
const int window_height = 768;
const int max_enemies = 5;
const int max_enemy_bullets = 5;

Text text1;

Font font;
Font font1;

Sprite playerSprite;
Texture playerTexture;
Sprite heartSprite[3];
Texture heartTexture;
Texture blueShipTexture;
Texture greenShipTexture;
Texture redShipTexture;
Sprite enemySprites[max_enemies];

RenderWindow window(VideoMode(1366, 768), "Space Shooter");

int CheckGame()
{
    RenderWindow ahindow(VideoMode(1366.f, 768.0f), "GAME FIRST");

    font.loadFromFile("GOUDYSTO.ttf");
    font1.loadFromFile("GOUDYSTO.ttf");

    //Startup text
    Text text;
    text.setFont(font1);
    text.setString("SPACE SHOOTER");
    text.setCharacterSize(70.0f);
    text.setFillColor(Color(255, 165, 0));
    text.setStyle(sf::Text::Bold);

    Text start;
    start.setFont(font);
    start.setString("Start Game");
    start.setCharacterSize(40.0f);
    start.setFillColor(Color::White);

    Text exit;
    exit.setFont(font);
    exit.setString("Exit Game");
    exit.setCharacterSize(40.0f);
    exit.setFillColor(Color::White);

    Text LB;
    LB.setFont(font);
    LB.setString("Leader Board");
    LB.setCharacterSize(40.0f);
    LB.setFillColor(Color::White);

    text.setPosition(Vector2f(100.0f, 50.0f));
    start.setPosition(Vector2f(100.0f, 300.0f));
    exit.setPosition(Vector2f(100.0f, 400.0f));
    LB.setPosition(Vector2f(100.0f, 500.0f));

    RectangleShape Image;
    Image.setSize(Vector2f(ahindow.getSize().x, ahindow.getSize().y));
    Texture ImageDF;
    ImageDF.loadFromFile("wallpaper2.jpg");
    Image.setTexture(&ImageDF);
    Image.setPosition(0.0f, 0.0f);
    Image.setOutlineColor(Color::Black);
    Event event;
    while (ahindow.isOpen())
    {
        if (ahindow.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {

                ahindow.close();
                return 9;
                break;
            }
        }
        if (Mouse::getPosition(ahindow).x <= start.getPosition().x + start.getCharacterSize() * 7 && Mouse::getPosition(ahindow).x >= start.getPosition().x && Mouse::getPosition(ahindow).y >= start.getPosition().y && Mouse::getPosition(ahindow).y <= (start.getPosition().y + start.getCharacterSize()))
        {
            start.setFillColor(Color(255, 255, 255, 180));
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                return 0;
            }
        }
        else
        {
            start.setFillColor(Color::White);
        }
        if (Mouse::getPosition(ahindow).x <= exit.getPosition().x + exit.getCharacterSize() * 6 && Mouse::getPosition(ahindow).x >= exit.getPosition().x && Mouse::getPosition(ahindow).y >= exit.getPosition().y && Mouse::getPosition(ahindow).y <= exit.getPosition().y + exit.getCharacterSize())
        {
            exit.setFillColor(Color(255, 255, 255, 180));
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                return 9;
            }
        }
        else
        {
            exit.setFillColor(Color::White);
        }
        if (Mouse::getPosition(ahindow).x <= (LB.getPosition().x + LB.getCharacterSize() * 8) && Mouse::getPosition(ahindow).x >= LB.getPosition().x && Mouse::getPosition(ahindow).y >= LB.getPosition().y && Mouse::getPosition(ahindow).y <= (LB.getPosition().y + LB.getCharacterSize()))
        {
            LB.setFillColor(Color(255, 255, 255, 180));
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                return 0;
            }
        }
        else
        {
            LB.setFillColor(Color::White);
        }
        ahindow.clear(Color::Black);
        //ahindow.draw(options);
        ahindow.draw(Image);
        ahindow.draw(text);
        ahindow.draw(start);
        ahindow.draw(exit);
        ahindow.draw(LB);
        ahindow.display();
    }
}

int PauseGame()//change zkhan
{
    RenderWindow shindow(VideoMode(1366.f, 768.f), "Pause");
    Font font;
    font.loadFromFile("GOUDYSTO.ttf");

    Text tet;
    tet.setFont(font);
    tet.setString("GAME PAUSED");
    tet.setCharacterSize(50.0f);
    tet.setFillColor(Color(255, 165, 0));

    Text resume;
    resume.setFont(font);
    resume.setString("RESUME GAME");
    resume.setCharacterSize(40.0f);
    resume.setFillColor(Color::White);

    Text eit;
    eit.setFont(font);
    eit.setString("EXIT GAME");
    eit.setCharacterSize(40.0f);
    eit.setFillColor(Color::White);

    Text BL;
    BL.setFont(font);
    BL.setString("LEADER BOARD");
    BL.setCharacterSize(40.0f);
    BL.setFillColor(Color::White);

    tet.setPosition(Vector2f(100.0f, 50.0f));
    resume.setPosition(Vector2f(100.0f, 300.0f));
    eit.setPosition(Vector2f(100.0f, 400.0f));
    BL.setPosition(Vector2f(100.0f, 500.0f));

    RectangleShape mage;
    mage.setSize(Vector2f(shindow.getSize().x, shindow.getSize().y));
    Texture mageDF;
    mageDF.loadFromFile("wallpaper1.jpg");
    mage.setTexture(&mageDF);
    mage.setPosition(0.0f, 0.0f);
    mage.setOutlineColor(Color::Black);
    Event evnt;
    while (shindow.isOpen())
    {
        if (Mouse::getPosition(shindow).x <= resume.getPosition().x + resume.getCharacterSize() * 7 && Mouse::getPosition(shindow).x >= resume.getPosition().x && Mouse::getPosition(shindow).y >= resume.getPosition().y && Mouse::getPosition(shindow).y <= (resume.getPosition().y + resume.getCharacterSize()))
        {
            resume.setFillColor(Color(255, 255, 255, 180));
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                shindow.close();
                return 0;
            }
        }
        else
        {
            resume.setFillColor(Color::White);
        }
        if (Mouse::getPosition(shindow).x <= eit.getPosition().x + eit.getCharacterSize() * 6 && Mouse::getPosition(shindow).x >= eit.getPosition().x && Mouse::getPosition(shindow).y >= eit.getPosition().y && Mouse::getPosition(shindow).y <= eit.getPosition().y + eit.getCharacterSize())
        {
            eit.setFillColor(Color(255, 255, 255, 180));
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                shindow.close();
                return 9;

            }
        }
        else
        {
            eit.setFillColor(Color::White);
        }
        if (Mouse::getPosition(shindow).x <= (BL.getPosition().x + BL.getCharacterSize() * 8) && Mouse::getPosition(shindow).x >= BL.getPosition().x && Mouse::getPosition(shindow).y >= BL.getPosition().y && Mouse::getPosition(shindow).y <= (BL.getPosition().y + BL.getCharacterSize()))
        {
            BL.setFillColor(Color(255, 255, 255, 180));
            if (Mouse::Button::Left)
            {
                return 6;
            }
        }
        else
        {
            BL.setFillColor(Color::White);
        }
        shindow.clear(Color::Black);
        shindow.draw(mage);
        shindow.draw(tet);
        shindow.draw(resume);
        shindow.draw(eit);
        shindow.draw(BL);
        shindow.display();
    }
}

void Gameover(string a, int b)//change zkhan
{

    RenderWindow lindow(VideoMode(1366.f, 768.f), "Pause");
    Font font;
    font.loadFromFile("GOUDYSTO.ttf");
    Text Game;
    Game.setFont(font);
    Game.setString("GAME OVER!");
    Game.setCharacterSize(70.f);
    Game.setFillColor(Color::Red);
    Game.setPosition(
        (lindow.getSize().x - Game.getGlobalBounds().width) / 2,
        lindow.getSize().y / 3
    );

    Text Name;
    Name.setFont(font);
    Name.setString("Name : " + a);
    Name.setCharacterSize(40.0f);
    Name.setFillColor(Color::White);
    Name.setPosition(
        (lindow.getSize().x - Name.getGlobalBounds().width) / 2,
        (lindow.getSize().y / 3) + 150
    );

    Text Score;
    Score.setFont(font);
    Score.setString("Score : " + to_string(b));
    Score.setCharacterSize(40.0f);
    Score.setFillColor(Color::White);
    Score.setPosition(
        (lindow.getSize().x - Score.getGlobalBounds().width) / 2,
        (lindow.getSize().y / 3) + 250
    );

    while (lindow.isOpen())
    {
        Event event;
        while (lindow.pollEvent(event))
        {
            if (event.type == Event::Closed)
                lindow.close();
        }
        lindow.clear(Color::Black);
        lindow.draw(Game);
        lindow.draw(Name);
        lindow.draw(Score);
        lindow.display();
    }
}

void ingame_text()
{
    font.loadFromFile("timesnewromanbold.ttf");
    text1.setFont(font);
    text1.setCharacterSize(25);
    text1.setFillColor(Color::White);
    text1.setString("Points: ");
    text1.setPosition(10.f, 10.f); // top-left corner
}

float clamp(float value, float min, float max)
{
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

//game state variables
RectangleShape player(Vector2f(50.f, 50.f));
CircleShape fireball(5.f);
RectangleShape enemies[max_enemies];
bool enemyActive[max_enemies];
int enemyHealth[max_enemies];
bool fireballActive = false;
int playerHealth = 3;
int playerScore = 0;
float collisionCooldown = 0.f; //timer for collision cooldown
const float collisionCooldownTime = 0.5f; //cooldown time period(0.5 secs)

// Bullet struct for enemy bullets
struct Bullet
{
    CircleShape shape;
    bool active = false;
};

// Enemy bullets fixed-size array
Bullet enemyBullets[max_enemies][max_enemy_bullets];

void spawnEnemy(RectangleShape* enemies, bool* enemyActive, int* enemyHealth) {
    for (int i = 0; i < max_enemies; i++)
    {
        if (!enemyActive[i])
        {
            enemies[i].setPosition(
                static_cast<float>(rand() % static_cast<int>(window.getSize().x - enemies[i].getSize().x)),
                0.f
            );

            int type = rand() % 3;

            switch (type)
            {
            case 0:
                enemies[i].setSize(Vector2f(30.f, 30.f));
                enemySprites[i].setTexture(redShipTexture);
                enemyHealth[i] = 1;
                break;

            case 1:
                enemies[i].setSize(Vector2f(50.f, 50.f));
                enemySprites[i].setTexture(greenShipTexture);
                enemyHealth[i] = 2;
                break;

            case 2:
                enemies[i].setSize(Vector2f(70.f, 70.f));
                enemySprites[i].setTexture(blueShipTexture);
                enemyHealth[i] = 3;
                break;
            }

            // Set the position of both the rectangle and the sprite
            float posX = static_cast<float>(rand() % (window_width - static_cast<int>(enemies[i].getSize().x)));
            float posY = 0.f;
            enemies[i].setPosition(posX, posY);
            enemySprites[i].setPosition(posX, posY);

            enemyActive[i] = true; // Activate this enemy
            break;
        }
    }
}

bool isColliding(const CircleShape& fireball, const Sprite& enemySprite) {
    return fireball.getGlobalBounds().intersects(enemySprite.getGlobalBounds());
}

bool PlayerCollidingEnemy(const Sprite& playerSprite, const Sprite& enemySprite)
{
    return playerSprite.getGlobalBounds().intersects(enemySprite.getGlobalBounds());
}

void updateFireball(RectangleShape* enemies, bool* enemyActive, int* enemyHealth, float deltaTime)
{
    if (fireballActive)
    {
        fireball.move(0.f, -500.f * deltaTime); //move fireball upward

        //deactivate fireball if moves out of bounds
        if (fireball.getPosition().y < 0)
        {
            fireballActive = false;
        }

        //collisions with enemies
        for (int i = 0; i < max_enemies; i++)
        {
            if (enemyActive[i] && isColliding(fireball, enemySprites[i]))
            {
                enemyHealth[i]--;
                fireballActive = false; //deactivate fireball
                if (enemyHealth[i] <= 0)
                {
                    int points = 0;
                    float enemyWidth = enemies[i].getSize().x;

                    if(enemyWidth == 30.f)
                    {
                        points = 10;
                    }
                    else if(enemyWidth == 50.f)
                    {
                        points = 20;
                    }
                    else if(enemyWidth == 70.f)
                    {
                        points = 30;
                    }

                    playerScore += points;
                    enemyActive[i] = false;

                    cout << "Enemy destroyed! Points: " << points << " Score: " << playerScore << endl;
                }
                else
                {
                    cout << "Enemy hit!" << endl;
                }
                break;
            }
        }
    }
}

void updateEnemies(RectangleShape* enemies, bool* enemyActive, float deltaTime)
{
    collisionCooldown -= deltaTime;
    for (int i = 0; i < max_enemies; i++)
    {
        if (enemyActive[i])
        {
            enemySprites[i].move(0.f, level * 100.f * deltaTime); //move sprite with the rectangle

            //if enemy moves out of bounds
            if (enemies[i].getPosition().y > window_height)
            {
                enemyActive[i] = false;
            }

            if (PlayerCollidingEnemy(playerSprite, enemySprites[i]))
            {
                if (collisionCooldown <= 0.f) {
                    playerHealth--;
                    collisionCooldown = collisionCooldownTime;
                    cout << "Player collided with an enemy! Health: " << playerHealth << endl;
                }
                enemyActive[i] = false;
            }

            //bullets shooting logic
            if (rand() * level % 500 < 2)
            {
                for (int j = 0; j < max_enemy_bullets; j++)
                {
                    if (!enemyBullets[i][j].active)
                    {
                        enemyBullets[i][j].shape.setRadius(5.f);
                        enemyBullets[i][j].shape.setFillColor(Color::Green);
                        enemyBullets[i][j].shape.setPosition(
                            enemies[i].getPosition().x + enemies[i].getSize().x / 2.f,
                            enemies[i].getPosition().y + enemies[i].getSize().y
                        );
                        enemyBullets[i][j].active = true;
                        break;
                    }
                }
            }
        }
    }

    //move enemy bullets and if collides with our ship
    for (int i = 0; i < max_enemies; i++)
    {
        for (int j = 0; j < max_enemy_bullets; j++)
        {
            Bullet& bullet = enemyBullets[i][j];
            if (bullet.active)
            {
                bullet.shape.move(0.f, level * 200.f * deltaTime); //downward speed

                //deactivate bullet if moves out of bounds
                if (bullet.shape.getPosition().y > window_height)
                {
                    bullet.active = false;
                }

                //collision with player
                if (bullet.shape.getGlobalBounds().intersects(playerSprite.getGlobalBounds()))
                {
                    if (collisionCooldown <= 0.f) //cooldown for bullets
                    {
                        playerHealth--;
                        collisionCooldown = collisionCooldownTime; //reset cooldown
                        cout << "Player hit by bullet! Health: " << playerHealth << endl;
                    }
                    bullet.active = false; //deactivate bullet
                }
            }
        }
    }
}

//to draw everything on screen
void draw(RenderWindow& window, RectangleShape* enemies, bool* enemyActive,RectangleShape image)
{
    window.clear();
    window.draw(image);
    window.draw(playerSprite);

    for (int i = 0; i < max_enemies; i++)
    {
        if (enemyActive[i])
        {
            window.draw(enemySprites[i]);
        }
    }

    //enemy bullets
    for (int i = 0; i < max_enemies; i++)
    {
        for (int j = 0; j < max_enemy_bullets; j++)
        {
            if (enemyBullets[i][j].active)
            {
                window.draw(enemyBullets[i][j].shape);
            }
        }
    }

    if (fireballActive)
    {
        window.draw(fireball);
    }

    for (int i = 0; i < playerHealth; i++)
    {
        window.draw(heartSprite[i]);
    }

    window.draw(text1);
    window.display();
}

int main()
{

    //spaceship texture
    if (!playerTexture.loadFromFile("ship.png"))
    {
        cerr << "Error: Could not load spaceship.png" << endl;
        return -1; // Exit if texture loading fails
    }

    playerSprite.setTexture(playerTexture);
    playerSprite.setScale(0.15f, 0.15f);
    playerSprite.setPosition(window_width / 2.f, window_height - 100.f);

    if (!blueShipTexture.loadFromFile("blueship.png"))
    {
        cerr << "Error: Could not load blueship.png" << endl;
        return -1;
    }
    if (!greenShipTexture.loadFromFile("greenship.png"))
    {
        cerr << "Error: Could not load greenship.png" << endl;
        return -1;
    }
    if (!redShipTexture.loadFromFile("redship.png"))
    {
        cerr << "Error: Could not load redship.png" << endl;
        return -1;
    }

    //heart texture
    if (!heartTexture.loadFromFile("heart.png"))
    {
        cerr << "Error: Could not load heart.png" << endl;
        return -1;
    }

    //heart sprites
    for (int i = 0; i < 3; i++)
    {

        heartSprite[i].setTexture(heartTexture);
        heartSprite[i].setScale(2.f, 2.f);
        heartSprite[i].setPosition(window_width - (i + 1) * (heartSprite[i].getGlobalBounds().width + 10.f), 10.f);
    }

    ingame_text();

    if (CheckGame() == 0)
    {
        window.setFramerateLimit(60);

        RectangleShape image;
        image.setSize(Vector2f(window.getSize().x, window.getSize().y));
        Texture imageDF;
        imageDF.loadFromFile("22.jpg");
        image.setTexture(&imageDF);
        image.setPosition(0.0f, 0.0f);
        image.setOutlineColor(Color::Black);

        // Initialize player
        player.setFillColor(Color::White);
        player.setPosition(window_width / 2.f, window_height - 100.f);

        // Initialize fireball
        fireball.setFillColor(Color::White);

        // Initialize enemies
        for (int i = 0; i < max_enemies; i++)
        {
            enemyActive[i] = false;
        }

        //game clock and spawn timer
        Clock clock;
        float spawnTimer = 0.f;
        const float spawnInterval = 1.f;
        float deltaTime;

        // Game loop
        while (window.isOpen())
        {
            deltaTime = clock.restart().asSeconds();

            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
            }

            //pause key (P)
            if (Keyboard::isKeyPressed(Keyboard::P))
            {
                int result = PauseGame();

                if (result == 9) //exit game
                {
                    window.close();
                }
                else if (result == 0) //leaderboard
                {
                    // Call leaderboard function here (if implemented)
                    //DisplayLeaderboard();
                }
            }

            //player movement
            if (Keyboard::isKeyPressed(Keyboard::A)) //left
            {
                playerSprite.move(-300.f * deltaTime, 0.f);
            }
            if (Keyboard::isKeyPressed(Keyboard::D)) //right
            {
                playerSprite.move(300.f * deltaTime, 0.f);
            }
            if (Keyboard::isKeyPressed(Keyboard::W)) //up
            {
                playerSprite.move(0.f, -300.f * deltaTime);
            }
            if (Keyboard::isKeyPressed(Keyboard::S)) //down
            {
                playerSprite.move(0.f, 300.f * deltaTime);
            }

            //clamp player position to the screen
            playerSprite.setPosition(
                clamp(playerSprite.getPosition().x, 0.f, window_width - playerSprite.getGlobalBounds().width),
                clamp(playerSprite.getPosition().y, 0.f, window_height - playerSprite.getGlobalBounds().height)
            );

            //fire fireball
            if (Keyboard::isKeyPressed(Keyboard::Space) && !fireballActive)
            {
                fireball.setPosition(
                    playerSprite.getPosition().x + playerSprite.getGlobalBounds().width / 2.f - fireball.getRadius(),
                    playerSprite.getPosition().y - fireball.getRadius()
                );
                fireballActive = true;
            }

            //spawn enemies at different times
            spawnTimer += deltaTime;
            if (spawnTimer >= spawnInterval)
            {
                spawnEnemy(enemies, enemyActive, enemyHealth);
                spawnTimer = 0.f;
            }

            //update game objects
            updateFireball(enemies, enemyActive, enemyHealth, deltaTime);
            updateEnemies(enemies, enemyActive, deltaTime);

            //draw everything
            draw(window, enemies, enemyActive, image);

            //check if game over
            if (playerHealth <= 0)
            {
                string playerName = "Player1";
                Gameover(playerName, playerScore);
                cout << "Game Over! Final Score: " << playerScore << endl;
                window.close();
            }
            if (playerScore >= 100)
            {
                level = 2;
            }
            if (playerScore >= 200)
            {
                level = 3;
            }

            stringstream ss;
            ss << "  LEVEl: " << level << endl << "  SCORE: " << playerScore;
            text1.setString(ss.str());
            window.draw(text1);
        }
    }
    system("pause");
}