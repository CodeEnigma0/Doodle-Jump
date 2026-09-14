/*
                 DOODLE JUMP PROJECT
                 IMPLEMENTED FEATURES
---------------------------------------------------------
1. PLAYER SYSTEM
   - Player character with custom graphical rendering.
   - Player horizontal movement.
   - Automatic jumping/bouncing from platforms.
   - Gravity-based vertical movement.
   - Jump power control.
   - Player-platform collision detection.
   - Camera follows the player as they move upward.

2. PLATFORM SYSTEM
   - Multiple platforms are generated for the game.
   - Platforms have different positions and sizes.
   - Moving platforms are supported.
   - Moving platforms can move between minimum and maximum
     horizontal boundaries.
   - Platform direction is controlled automatically.
   - Collision detection allows the player to land on platforms.

3. GAME PHYSICS
   - Gravity system.
   - Jump physics.
   - Horizontal movement speed.
   - Automatic vertical movement.
   - Platform collision response.
   - Falling/death detection.

4. CAMERA SYSTEM
   - Vertical camera movement.
   - Camera follows the player when the player reaches
     higher areas of the level.
   - Keeps the player visible while climbing.

5. BACKGROUND THEMES
   - Four different background worlds are implemented.
   - Theme 0: Sky World.
   - Theme 1: Volcanic World.
   - Theme 2: Frozen World.
   - Theme 3: Space World.
   - Background theme changes after each death.
   - Theme sequence:
       Sky -> Volcanic -> Frozen -> Space -> Sky -> ...
   - The theme system repeats every 4 deaths.
   - Background theme is controlled using:
       backgroundTheme = deathCount % 4;

6. SKY WORLD
   - Sky background.
   - Sun.
   - Clouds.
   - Mountains.
   - Trees.
   - Birds.
   - Natural environment graphics.

7. VOLCANIC WORLD
   - Volcanic-style background.
   - Mountains.
   - Volcanic smoke.
   - Ember/particle effects.
   - Dark volcanic environment.

8. FROZEN WORLD
   - Frozen/icy environment.
   - Snow-themed visual elements.
   - Frozen trees.
   - Snow/particle effects.
   - Cold environment graphics.

9. SPACE WORLD
   - Space-themed background.
   - Planets.
   - Stars.
   - Asteroids.
   - Space particle effects.

10. BACKGROUND ANIMATION
    - Moving birds.
    - Animated particles.
    - Volcanic particles/embers.
    - Snow particles.
    - Space particles/stars.
    - Continuous background animation.

11. PARTICLE SYSTEM
    - Particles are generated for environmental effects.
    - Particle positions are updated over time.
    - Particles are used for different background themes.
    - Supports visual effects such as smoke, snow, embers,
      and space effects.

12. BIRD ANIMATION
    - Birds are rendered in the sky environment.
    - Birds move horizontally.
    - Birds wrap/reposition when leaving the visible area.

13. GRAPHICS SYSTEM
    - 2D OpenGL graphics.
    - GLUT window and rendering system.
    - Orthographic 2D projection.
    - Custom shapes created using OpenGL primitives.
    - Circle drawing function.
    - Rectangle drawing function.
    - Triangle drawing function.
    - Custom mountains.
    - Custom clouds.
    - Custom trees.
    - Custom birds.
    - Custom sun.

14. GAME STATES
    - Active gameplay state.
    - Game Over state.
    - Win state.
    - Restart/reset functionality.
    - Game-over screen.
    - Win screen.

15. SCORE SYSTEM
    - Score is displayed on screen.
    - Score/text rendering is implemented.
    - Player progress is represented through the game UI.

16. DEATH SYSTEM
    - Player death is detected when the player falls.
    - Death counter is maintained.
    - Game-over sound is played after death.
    - Game state is reset after death.
    - Background theme changes according to death count.
    - Death count is preserved during game reset so the
      background sequence continues correctly.

17. RESTART SYSTEM
    - Game can be restarted using the R key.
    - Player position is reset.
    - Camera state is reset.
    - Platforms are recreated.
    - Game state is restored.
    - Death count/background theme are preserved.

18. SOUND SYSTEM
    - Background music support.
    - Jump sound effect.
    - Game-over sound effect.
    - Win sound effect.
    - Sound can be enabled/disabled.
    - Windows PlaySound API is used for sound effects.
    - MCI is used for looping background music.

19. KEYBOARD CONTROLS
    - A key: Move player left.
    - D key: Move player right.
    - Left Arrow: Move player left.
    - Right Arrow: Move player right.
    - Up Arrow: Jump/movement control.
    - R key: Restart game.
    - M key: Toggle sound.
    - ESC key: Exit the game.

20. ANIMATION LOOP
    - Timer-based game updates.
    - Game updates approximately every 16 milliseconds.
    - Continuous player movement.
    - Continuous platform movement.
    - Continuous background animation.
    - Continuous camera updates.
    - Screen is repeatedly redrawn.

21. WINDOW / DISPLAY SYSTEM
    - 600 x 800 game window.
    - OpenGL rendering context.
    - Orthographic coordinate system.
    - Window resizing support.
    - Display callback for rendering the complete game.

22. OBJECT IDENTIFICATION SYSTEM
    - Objects/functions are assigned IDs for project
      documentation and identification.

    Object IDs:
      OBJ-01  Player
      OBJ-02  Platform
      OBJ-03  Cloud
      OBJ-04  Tree
      OBJ-05  Bird
      OBJ-06  Particle
      OBJ-07  Sun
      OBJ-08  Mountain
      OBJ-09  Volcanic Smoke / Ember
      OBJ-10  Frozen Tree / Snow
      OBJ-11  Space Planet / Star
      OBJ-12  Asteroid
      OBJ-13  Game-Over Screen
      OBJ-14  Win Screen
      OBJ-15  Score / Text

23. ANIMATION IDENTIFICATION SYSTEM
    - Animation functions are assigned IDs for documentation.

    Animation IDs:
      ANIM-01  Player Movement / Physics
      ANIM-02  Platform Movement
      ANIM-03  Bird Animation
      ANIM-04  Particle Animation
      ANIM-05  Camera Movement
      ANIM-06  Keyboard Interaction
      ANIM-07  Scenario Change After Death
      ANIM-08  Game Reset
      ANIM-09  Timer / Frame Update

24. SOUND IDENTIFICATION SYSTEM
    - Sound-related functions are identified separately.

      SOUND-01  General Sound Playback
      SOUND-02  Jump Sound
      SOUND-03  Win Sound
      SOUND-04  Background Music Start
      SOUND-05  Background Music Stop

25. SUPPORT FUNCTIONS
    - Helper functions for drawing geometric shapes.
    - OpenGL initialization.
    - Window reshape handling.
    - Display/rendering callback.
    - Main GLUT initialization and callback registration.
-------------------------------------------------------------------
                    END OF FEATURES
*/


#include <windows.h>
#include <mmsystem.h>
#include <GL/glut.h>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

#pragma comment(lib, "winmm.lib")

using namespace std;


// SOUND SYSTEM

bool soundOn = true;
bool gameOverSoundPlayed = false;
bool winSoundPlayed = false;
bool backgroundMusicPlaying = false;

const char* BACKGROUND_MUSIC = "doodle_background.wav";

void startBackgroundMusic();
void stopBackgroundMusic();

// ID: SOUND-01
void playSound(const char* soundFile)
{
    if (!soundOn)
        return;

    PlaySoundA(
        soundFile,
        NULL,
        SND_FILENAME | SND_ASYNC | SND_NODEFAULT
    );
}

// ID: SOUND-02
void playJumpSound()
{
    playSound("jump.wav");
}

// ID: SOUND-07
void playGameOverSound()
{
    playSound("gameover.wav");
}

// ID: SOUND-03
void playWinSound()
{
    playSound("win.wav");
}
// ID: SOUND-04
void startBackgroundMusic()
{
    if (!soundOn)
        return;

    // Make sure any previous background music is closed
    mciSendStringA(
        "stop doodlebg",
        NULL,
        0,
        NULL
    );

    mciSendStringA(
        "close doodlebg",
        NULL,
        0,
        NULL
    );

    string command =
        "open \"" +
        string(BACKGROUND_MUSIC) +
        "\" type waveaudio alias doodlebg";

    MCIERROR openResult = mciSendStringA(
        command.c_str(),
        NULL,
        0,
        NULL
    );

    if (openResult != 0)
    {
        backgroundMusicPlaying = false;
        return;
    }

    MCIERROR playResult = mciSendStringA(
        "play doodlebg repeat",
        NULL,
        0,
        NULL
    );

    if (playResult == 0)
    {
        backgroundMusicPlaying = true;
    }
    else
    {
        backgroundMusicPlaying = false;

        mciSendStringA(
            "close doodlebg",
            NULL,
            0,
            NULL
        );
    }
}


// ID: SOUND-05
void stopBackgroundMusic()
{
    mciSendStringA(
        "stop doodlebg",
        NULL,
        0,
        NULL
    );

    mciSendStringA(
        "close doodlebg",
        NULL,
        0,
        NULL
    );

    backgroundMusicPlaying = false;
}




// GAME CONSTANTS

const int WIDTH = 600;
const int HEIGHT = 800;

float playerX = 277.5f;
float playerY = 135.0f;

const float playerWidth = 45.0f;
const float playerHeight = 55.0f;

float velocityX = 0.0f;
float velocityY = 0.0f;

const float moveSpeed = 5.0f;
const float gravity = -0.45f;
const float jumpPower = 12.0f;

bool canJump = true;

bool leftPressed = false;
bool rightPressed = false;

bool gameOver = false;
bool gameWon = false;

int score = 0;
int highestPlatform = 0;

float cameraY = 0.0f;



int backgroundTheme = 0;
int deathCount = 0;


// PLATFORM

struct Platform
{
    float x;
    float y;
    float width;
    float height;

    float speed;
    float minX;
    float maxX;
    int direction;

    bool moving;
};

const int PLATFORM_COUNT = 100;

Platform platforms[PLATFORM_COUNT];


// BIRD

struct Bird
{
    float x;
    float y;
    float speed;
    float size;
    float flap;
    float flapSpeed;
};

const int BIRD_COUNT = 7;

Bird birds[BIRD_COUNT] =
{
    {80,  620, 0.45f, 1.0f, 0.0f, 0.10f},
    {300, 520, 0.35f, 0.75f, 0.5f, 0.12f},
    {500, 670, 0.55f, 1.15f, 1.0f, 0.09f},
    {180, 310, 0.40f, 0.65f, 1.5f, 0.13f},
    {420, 400, 0.30f, 0.90f, 2.0f, 0.11f},
    {70,  190, 0.50f, 0.80f, 2.5f, 0.10f},
    {540, 300, 0.38f, 0.70f, 3.0f, 0.12f}
};


// PARTICLES

struct Particle
{
    float x;
    float y;
    float speed;
    float size;
};

const int PARTICLE_COUNT = 35;

Particle particles[PARTICLE_COUNT];


// CREATE PLATFORMS

void createPlatforms()
{
    // ID: OBJ-02
    platforms[0]  = {220, 80,   160, 15};
    platforms[1]  = {350, 210,  140, 15};
    platforms[2]  = {120, 340,  140, 15};
    platforms[3]  = {330, 470,  140, 15};
    platforms[4]  = {80,  600,  140, 15};
    platforms[5]  = {360, 730,  140, 15};
    platforms[6]  = {180, 860,  140, 15};
    platforms[7]  = {390, 990,  130, 15};
    platforms[8]  = {80,  1120, 140, 15};
    platforms[9]  = {330, 1250, 140, 15};
    platforms[10] = {140, 1380, 140, 15};
    platforms[11] = {380, 1510, 140, 15};
    platforms[12] = {220, 1640, 140, 15};
    platforms[13] = {70,  1770, 140, 15};
    platforms[14] = {370, 1900, 140, 15};
    platforms[15] = {180, 2030, 140, 15};
    platforms[16] = {400, 2160, 130, 15};
    platforms[17] = {90,  2290, 140, 15};
    platforms[18] = {300, 2420, 140, 15};
    platforms[19] = {150, 2550, 140, 15};
    platforms[20] = {390, 2680, 130, 15};
    platforms[21] = {70,  2810, 140, 15};
    platforms[22] = {250, 2940, 140, 15};
    platforms[23] = {420, 3070, 120, 15};
    platforms[24] = {130, 3200, 140, 15};
    platforms[25] = {330, 3330, 140, 15};
    platforms[26] = {60,  3460, 140, 15};
    platforms[27] = {220, 3590, 140, 15};
    platforms[28] = {400, 3720, 130, 15};
    platforms[29] = {150, 3850, 140, 15};
    platforms[30] = {350, 3980, 130, 15};
    platforms[31] = {100, 4110, 135, 15};
    platforms[32] = {300, 4240, 125, 15};
    platforms[33] = {430, 4370, 110, 15};
    platforms[34] = {180, 4500, 130, 15};
    platforms[35] = {60,  4630, 120, 15};
    platforms[36] = {330, 4760, 130, 15};
    platforms[37] = {200, 4890, 120, 15};
    platforms[38] = {410, 5020, 110, 15};
    platforms[39] = {100, 5150, 130, 15};
    platforms[40] = {300, 5280, 120, 15};
    platforms[41] = {450, 5410, 100, 15};
    platforms[42] = {160, 5540, 120, 15};
    platforms[43] = {40,  5670, 120, 15};
    platforms[44] = {300, 5800, 130, 15};
    platforms[45] = {190, 5930, 110, 15};
    platforms[46] = {420, 6060, 100, 15};
    platforms[47] = {80,  6190, 120, 15};
    platforms[48] = {270, 6320, 120, 15};
    platforms[49] = {400, 6450, 110, 15};
    platforms[50] = {150, 6580, 110, 15};
    platforms[51] = {330, 6710, 120, 15};
    platforms[52] = {60,  6840, 110, 15};
    platforms[53] = {250, 6970, 110, 15};
    platforms[54] = {430, 7100, 100, 15};
    platforms[55] = {170, 7230, 110, 15};
    platforms[56] = {350, 7360, 110, 15};
    platforms[57] = {80,  7490, 110, 15};
    platforms[58] = {280, 7620, 110, 15};
    platforms[59] = {420, 7750, 100, 15};
    platforms[60] = {180, 7880, 105, 15};
    platforms[61] = {360, 8010, 105, 15};
    platforms[62] = {70,  8140, 105, 15};
    platforms[63] = {260, 8270, 105, 15};
    platforms[64] = {430, 8400, 100, 15};
    platforms[65] = {140, 8530, 105, 15};
    platforms[66] = {320, 8660, 105, 15};
    platforms[67] = {50,  8790, 100, 15};
    platforms[68] = {230, 8920, 105, 15};
    platforms[69] = {400, 9050, 100, 15};
    platforms[70] = {100, 9180, 100, 15};
    platforms[71] = {290, 9310, 105, 15};
    platforms[72] = {440, 9440, 90, 15};
    platforms[73] = {170, 9570, 100, 15};
    platforms[74] = {350, 9700, 100, 15};
    platforms[75] = {60,  9830, 100, 15};
    platforms[76] = {250, 9960, 100, 15};
    platforms[77] = {420, 10090, 90, 15};
    platforms[78] = {130, 10220, 100, 15};
    platforms[79] = {330, 10350, 100, 15};
    platforms[80] = {70,  10480, 95, 15};
    platforms[81] = {250, 10610, 95, 15};
    platforms[82] = {420, 10740, 90, 15};
    platforms[83] = {150, 10870, 95, 15};
    platforms[84] = {330, 11000, 95, 15};
    platforms[85] = {50,  11130, 90, 15};
    platforms[86] = {230, 11260, 95, 15};
    platforms[87] = {410, 11390, 90, 15};
    platforms[88] = {120, 11520, 95, 15};
    platforms[89] = {300, 11650, 95, 15};
    platforms[90] = {450, 11780, 85, 15};
    platforms[91] = {180, 11910, 90, 15};
    platforms[92] = {350, 12040, 90, 15};
    platforms[93] = {70,  12170, 90, 15};
    platforms[94] = {250, 12300, 90, 15};
    platforms[95] = {420, 12430, 85, 15};
    platforms[96] = {140, 12560, 90, 15};
    platforms[97] = {320, 12690, 90, 15};
    platforms[98] = {60,  12820, 85, 15};
    platforms[99] = {280, 12950, 100, 15};


    for (int i = 0; i < PLATFORM_COUNT; i++)
    {
        platforms[i].moving = true;

        if (i == 0)
        {
            platforms[i].moving = false;
            platforms[i].speed = 0.0f;
            platforms[i].direction = 1;
            platforms[i].minX = platforms[i].x;
            platforms[i].maxX = platforms[i].x;

            continue;
        }

        float difficulty = i / 20.0f;

        platforms[i].speed =
            0.45f +
            difficulty * 0.12f;

        float movementRange;

        if (i < 20)
        {
            movementRange = 25.0f;
        }
        else if (i < 40)
        {
            movementRange = 35.0f;
        }
        else if (i < 60)
        {
            movementRange = 45.0f;
        }
        else if (i < 80)
        {
            movementRange = 55.0f;
        }
        else
        {
            movementRange = 65.0f;
        }

        platforms[i].minX =
            platforms[i].x -
            movementRange;

        platforms[i].maxX =
            platforms[i].x +
            movementRange;

        if (platforms[i].minX < 10)
            platforms[i].minX = 10;

        if (platforms[i].maxX +
            platforms[i].width >
            WIDTH - 10)
        {
            platforms[i].maxX =
                WIDTH -
                platforms[i].width -
                10;
        }

        if (i % 2 == 0)
            platforms[i].direction = 1;
        else
            platforms[i].direction = -1;
    }
}


// CREATE PARTICLES

void createParticles()
{
    // ID: OBJ-06
    for (int i = 0; i < PARTICLE_COUNT; i++)
    {
        particles[i].x =
            15 +
            rand() %
            (WIDTH - 30);

        particles[i].y =
            30 +
            rand() %
            (HEIGHT - 60);

        particles[i].speed =
            0.15f +
            (rand() % 10) / 25.0f;

        particles[i].size =
            1.0f +
            (rand() % 3);
    }
}


// BASIC DRAWING FUNCTIONS

void drawCircle(
    float cx,
    float cy,
    float radius)
{
    // ID: SUPPORT-01
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(cx, cy);

    for (int i = 0; i <= 40; i++)
    {
        float angle =
            2.0f *
            3.1415926f *
            i /
            40.0f;

        float x =
            cx +
            cos(angle) *
            radius;

        float y =
            cy +
            sin(angle) *
            radius;

        glVertex2f(x, y);
    }

    glEnd();
}


void drawRect(
    float x,
    float y,
    float w,
    float h)
{
    // ID: SUPPORT-02
    glBegin(GL_QUADS);

    glVertex2f(x, y);
    glVertex2f(x + w, y);
    glVertex2f(x + w, y + h);
    glVertex2f(x, y + h);

    glEnd();
}


void drawTriangle(
    float x1,
    float y1,
    float x2,
    float y2,
    float x3,
    float y3)
{
    // ID: SUPPORT-03
    glBegin(GL_TRIANGLES);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);

    glEnd();
}


void drawMountain(
    float x,
    float y,
    float width,
    float height)
{
    // ID: OBJ-08
    drawTriangle(
        x,
        y,
        x + width / 2.0f,
        y + height,
        x + width,
        y
    );
}


// CLOUD

void drawCloud(
    float x,
    float y,
    float size)
{
    // ID: OBJ-03
    glEnable(GL_BLEND);

    glBlendFunc(
        GL_SRC_ALPHA,
        GL_ONE_MINUS_SRC_ALPHA
    );

    glColor4f(
        1.0f,
        1.0f,
        1.0f,
        0.72f
    );

    drawCircle(
        x,
        y,
        size * 0.42f
    );

    drawCircle(
        x + size * 0.35f,
        y + size * 0.12f,
        size * 0.55f
    );

    drawCircle(
        x + size * 0.75f,
        y,
        size * 0.40f
    );

    drawCircle(
        x + size * 0.48f,
        y - size * 0.08f,
        size * 0.43f
    );

    glDisable(GL_BLEND);
}


// TREE

void drawTree(
    float x,
    float y,
    float size)
{
    // ID: OBJ-04
    glColor3f(
        0.10f,
        0.30f,
        0.18f
    );

    drawCircle(
        x,
        y + size * 0.08f,
        size * 0.18f
    );

    glColor3f(
        0.36f,
        0.18f,
        0.07f
    );

    drawRect(
        x - size * 0.07f,
        y,
        size * 0.14f,
        size * 0.48f
    );

    glColor3f(
        0.06f,
        0.32f,
        0.12f
    );

    drawCircle(
        x,
        y + size * 0.58f,
        size * 0.30f
    );

    drawCircle(
        x - size * 0.20f,
        y + size * 0.46f,
        size * 0.25f
    );

    drawCircle(
        x + size * 0.20f,
        y + size * 0.46f,
        size * 0.25f
    );

    glColor3f(
        0.12f,
        0.58f,
        0.20f
    );

    drawCircle(
        x,
        y + size * 0.70f,
        size * 0.23f
    );

    drawCircle(
        x - size * 0.18f,
        y + size * 0.58f,
        size * 0.20f
    );

    drawCircle(
        x + size * 0.18f,
        y + size * 0.58f,
        size * 0.20f
    );
}


// BIRD

void drawBird(
    float x,
    float y,
    float size,
    float flap)
{
    // ID: OBJ-05
    float wingOffset =
        sin(flap) *
        7.0f *
        size;

    glEnable(GL_BLEND);

    glBlendFunc(
        GL_SRC_ALPHA,
        GL_ONE_MINUS_SRC_ALPHA
    );

    glColor4f(
        0.05f,
        0.10f,
        0.18f,
        0.18f
    );

    drawCircle(
        x,
        y,
        10.0f * size
    );

    glDisable(GL_BLEND);


    glColor3f(
        0.08f,
        0.12f,
        0.20f
    );

    drawCircle(
        x,
        y,
        7.0f * size
    );

    drawCircle(
        x + 7.0f * size,
        y + 4.0f * size,
        5.0f * size
    );


    glColor3f(
        0.16f,
        0.22f,
        0.32f
    );

    drawCircle(
        x + 3.0f * size,
        y - 2.0f * size,
        5.0f * size
    );


    glColor3f(
        0.05f,
        0.08f,
        0.15f
    );

    glBegin(GL_TRIANGLES);

    glVertex2f(
        x - 2.0f * size,
        y + 2.0f * size
    );

    glVertex2f(
        x - 18.0f * size,
        y + wingOffset
    );

    glVertex2f(
        x - 5.0f * size,
        y - 6.0f * size
    );

    glEnd();


    glBegin(GL_TRIANGLES);

    glVertex2f(
        x + 2.0f * size,
        y + 3.0f * size
    );

    glVertex2f(
        x + 17.0f * size,
        y + wingOffset
    );

    glVertex2f(
        x + 6.0f * size,
        y - 5.0f * size
    );

    glEnd();


    glBegin(GL_TRIANGLES);

    glVertex2f(
        x - 5.0f * size,
        y + 1.0f * size
    );

    glVertex2f(
        x - 17.0f * size,
        y + 9.0f * size
    );

    glVertex2f(
        x - 13.0f * size,
        y - 3.0f * size
    );

    glEnd();


    glColor3f(
        1.0f,
        0.60f,
        0.12f
    );

    glBegin(GL_TRIANGLES);

    glVertex2f(
        x + 11.0f * size,
        y + 5.0f * size
    );

    glVertex2f(
        x + 19.0f * size,
        y + 2.0f * size
    );

    glVertex2f(
        x + 11.0f * size,
        y - 1.0f * size
    );

    glEnd();


    glColor3f(
        1.0f,
        1.0f,
        1.0f
    );

    drawCircle(
        x + 9.0f * size,
        y + 6.0f * size,
        1.8f * size
    );


    glColor3f(
        0.0f,
        0.0f,
        0.0f
    );

    drawCircle(
        x + 9.4f * size,
        y + 6.0f * size,
        0.9f * size
    );
}


// SUN

void drawSun()
{
    // ID: OBJ-07
    glEnable(GL_BLEND);

    glBlendFunc(
        GL_SRC_ALPHA,
        GL_ONE_MINUS_SRC_ALPHA
    );

    glColor4f(
        1.0f,
        0.82f,
        0.18f,
        0.08f
    );

    drawCircle(
        500,
        680,
        95
    );

    glColor4f(
        1.0f,
        0.86f,
        0.20f,
        0.12f
    );

    drawCircle(
        500,
        680,
        72
    );

    glDisable(GL_BLEND);


    glColor3f(
        1.0f,
        0.78f,
        0.12f
    );

    drawCircle(
        500,
        680,
        42
    );


    glColor3f(
        1.0f,
        0.90f,
        0.38f
    );

    drawCircle(
        490,
        692,
        11
    );
}


// BACKGROUND

void drawBackground()
{
    // ID: OBJ-07, OBJ-08, OBJ-09, OBJ-10, OBJ-11, OBJ-12
    // THEME 0 - ORIGINAL SKY

    if (backgroundTheme == 0)
    {
        glBegin(GL_QUADS);

        glColor3f(
            0.28f,
            0.58f,
            0.92f
        );

        glVertex2f(0, 0);
        glVertex2f(WIDTH, 0);

        glColor3f(
            0.78f,
            0.94f,
            1.0f
        );

        glVertex2f(WIDTH, HEIGHT);
        glVertex2f(0, HEIGHT);

        glEnd();


        glBegin(GL_QUADS);

        glColor3f(
            0.48f,
            0.78f,
            0.94f
        );

        glVertex2f(0, 0);
        glVertex2f(WIDTH, 0);

        glColor3f(
            0.65f,
            0.86f,
            0.95f
        );

        glVertex2f(WIDTH, 250);
        glVertex2f(0, 250);

        glEnd();


        drawSun();


        glColor3f(
            0.62f,
            0.76f,
            0.82f
        );

        drawMountain(
            -120,
            80,
            330,
            260
        );

        drawMountain(
            100,
            80,
            360,
            310
        );

        drawMountain(
            330,
            80,
            370,
            280
        );


        glColor3f(
            0.94f,
            0.98f,
            1.0f
        );

        drawTriangle(
            145,
            325,
            280,
            390,
            335,
            325
        );

        drawTriangle(
            390,
            325,
            505,
            360,
            575,
            325
        );

        drawTriangle(
            5,
            300,
            45,
            350,
            90,
            300
        );


        glColor3f(
            0.40f,
            0.65f,
            0.65f
        );

        drawMountain(
            -100,
            50,
            280,
            180
        );

        drawMountain(
            160,
            50,
            300,
            210
        );

        drawMountain(
            420,
            50,
            260,
            190
        );


        drawCloud(40, 650, 48);
        drawCloud(275, 570, 62);
        drawCloud(430, 535, 45);
        drawCloud(170, 445, 42);
        drawCloud(480, 275, 55);


        drawTree(25, 55, 90);
        drawTree(85, 50, 70);
        drawTree(145, 45, 55);
        drawTree(520, 50, 90);
        drawTree(575, 45, 70);


        glEnable(GL_BLEND);

        glBlendFunc(
            GL_SRC_ALPHA,
            GL_ONE_MINUS_SRC_ALPHA
        );

        for (int i = 0; i < PARTICLE_COUNT; i++)
        {
            float alpha =
                0.25f +
                0.25f *
                sin(particles[i].y * 0.03f);

            glColor4f(
                1.0f,
                1.0f,
                0.88f,
                alpha
            );

            drawCircle(
                particles[i].x,
                particles[i].y,
                particles[i].size
            );
        }

        glDisable(GL_BLEND);


        for (int i = 0; i < BIRD_COUNT; i++)
        {
            drawBird(
                birds[i].x,
                birds[i].y,
                birds[i].size,
                birds[i].flap
            );
        }
    }


    // THEME 1 - VOLCANIC WORLD

    else if (backgroundTheme == 1)
    {
        // Red / orange sky

        glBegin(GL_QUADS);

        glColor3f(
            0.18f,
            0.015f,
            0.005f
        );

        glVertex2f(0, 0);
        glVertex2f(WIDTH, 0);

        glColor3f(
            0.95f,
            0.20f,
            0.03f
        );

        glVertex2f(WIDTH, HEIGHT);
        glVertex2f(0, HEIGHT);

        glEnd();


        // Large lava glow

        glEnable(GL_BLEND);

        glBlendFunc(
            GL_SRC_ALPHA,
            GL_ONE_MINUS_SRC_ALPHA
        );

        glColor4f(
            1.0f,
            0.20f,
            0.02f,
            0.12f
        );

        drawCircle(
            470,
            650,
            130
        );

        glColor4f(
            1.0f,
            0.40f,
            0.05f,
            0.20f
        );

        drawCircle(
            470,
            650,
            95
        );

        glColor4f(
            1.0f,
            0.65f,
            0.08f,
            0.30f
        );

        drawCircle(
            470,
            650,
            55
        );

        glDisable(GL_BLEND);


        // Orange sun / lava ball

        glColor3f(
            1.0f,
            0.45f,
            0.05f
        );

        drawCircle(
            470,
            650,
            38
        );


        // Distant mountains

        glColor3f(
            0.28f,
            0.035f,
            0.025f
        );

        drawMountain(
            -130,
            70,
            350,
            280
        );

        drawMountain(
            90,
            70,
            370,
            320
        );

        drawMountain(
            350,
            70,
            380,
            280
        );


        // Dark foreground mountains

        glColor3f(
            0.055f,
            0.015f,
            0.012f
        );

        drawMountain(
            -120,
            30,
            330,
            190
        );

        drawMountain(
            130,
            30,
            320,
            230
        );

        drawMountain(
            390,
            30,
            320,
            200
        );


        // Volcano glow

        glEnable(GL_BLEND);

        glBlendFunc(
            GL_SRC_ALPHA,
            GL_ONE_MINUS_SRC_ALPHA
        );

        glColor4f(
            1.0f,
            0.10f,
            0.01f,
            0.30f
        );

        drawCircle(
            275,
            245,
            70
        );

        glColor4f(
            1.0f,
            0.40f,
            0.02f,
            0.45f
        );

        drawCircle(
            275,
            245,
            38
        );

        glDisable(GL_BLEND);


        // Lava crater

        glColor3f(
            1.0f,
            0.30f,
            0.02f
        );

        drawCircle(
            275,
            245,
            20
        );


        // Smoke

        glEnable(GL_BLEND);

        glBlendFunc(
            GL_SRC_ALPHA,
            GL_ONE_MINUS_SRC_ALPHA
        );

        glColor4f(
            0.08f,
            0.05f,
            0.05f,
            0.60f
        );

        drawCircle(
            275,
            310,
            28
        );

        drawCircle(
            290,
            350,
            35
        );

        drawCircle(
            270,
            400,
            42
        );

        drawCircle(
            300,
            455,
            32
        );

        glDisable(GL_BLEND);


        // Volcanic embers

        glEnable(GL_BLEND);

        glBlendFunc(
            GL_SRC_ALPHA,
            GL_ONE_MINUS_SRC_ALPHA
        );

        for (int i = 0; i < PARTICLE_COUNT; i++)
        {
            float pulse =
                0.45f +
                0.40f *
                sin(particles[i].y * 0.07f);

            glColor4f(
                1.0f,
                0.25f,
                0.02f,
                pulse
            );

            drawCircle(
                particles[i].x,
                particles[i].y,
                particles[i].size * 1.2f
            );
        }

        glDisable(GL_BLEND);


        // Small birds

        for (int i = 0; i < BIRD_COUNT; i++)
        {
            drawBird(
                birds[i].x,
                birds[i].y,
                birds[i].size * 0.55f,
                birds[i].flap
            );
        }
    }


    // THEME 2 - FROZEN WORLD

    else if (backgroundTheme == 2)
    {
        // Blue / white gradient

        glBegin(GL_QUADS);

        glColor3f(
            0.35f,
            0.65f,
            0.90f
        );

        glVertex2f(0, 0);
        glVertex2f(WIDTH, 0);

        glColor3f(
            0.88f,
            0.96f,
            1.0f
        );

        glVertex2f(WIDTH, HEIGHT);
        glVertex2f(0, HEIGHT);

        glEnd();


        // Moon glow

        glEnable(GL_BLEND);

        glBlendFunc(
            GL_SRC_ALPHA,
            GL_ONE_MINUS_SRC_ALPHA
        );

        glColor4f(
            0.80f,
            0.92f,
            1.0f,
            0.15f
        );

        drawCircle(
            480,
            670,
            100
        );

        glColor4f(
            0.90f,
            0.96f,
            1.0f,
            0.22f
        );

        drawCircle(
            480,
            670,
            70
        );

        glDisable(GL_BLEND);


        // Moon

        glColor3f(
            0.95f,
            0.98f,
            1.0f
        );

        drawCircle(
            480,
            670,
            43
        );


        // Moon shadow

        glColor3f(
            0.68f,
            0.82f,
            0.92f
        );

        drawCircle(
            497,
            683,
            37
        );


        // Distant snowy mountains

        glColor3f(
            0.50f,
            0.68f,
            0.82f
        );

        drawMountain(
            -130,
            70,
            350,
            280
        );

        drawMountain(
            100,
            70,
            370,
            320
        );

        drawMountain(
            350,
            70,
            380,
            280
        );


        // Snow caps

        glColor3f(
            0.96f,
            0.99f,
            1.0f
        );

        drawTriangle(
            25,
            270,
            95,
            350,
            165,
            270
        );

        drawTriangle(
            175,
            300,
            285,
            390,
            395,
            300
        );

        drawTriangle(
            395,
            280,
            475,
            350,
            555,
            280
        );


        // Foreground mountains

        glColor3f(
            0.25f,
            0.45f,
            0.60f
        );

        drawMountain(
            -120,
            30,
            330,
            190
        );

        drawMountain(
            140,
            30,
            300,
            210
        );

        drawMountain(
            390,
            30,
            300,
            170
        );


        // Ice trees - trunks

        glColor3f(
            0.25f,
            0.38f,
            0.48f
        );

        drawRect(
            45,
            35,
            10,
            65
        );

        drawRect(
            105,
            30,
            9,
            70
        );

        drawRect(
            530,
            30,
            10,
            75
        );

        drawRect(
            580,
            25,
            9,
            70
        );


        // Ice tree foliage

        glColor3f(
            0.75f,
            0.90f,
            0.97f
        );

        drawTriangle(
            20,
            70,
            50,
            145,
            80,
            70
        );

        drawTriangle(
            80,
            65,
            110,
            150,
            140,
            65
        );

        drawTriangle(
            500,
            65,
            535,
            155,
            570,
            65
        );

        drawTriangle(
            550,
            60,
            585,
            145,
            620,
            60
        );


        // Snow particles

        glEnable(GL_BLEND);

        glBlendFunc(
            GL_SRC_ALPHA,
            GL_ONE_MINUS_SRC_ALPHA
        );

        for (int i = 0; i < PARTICLE_COUNT; i++)
        {
            float snowAlpha =
                0.50f +
                0.40f *
                sin(particles[i].y * 0.05f);

            glColor4f(
                1.0f,
                1.0f,
                1.0f,
                snowAlpha
            );

            drawCircle(
                particles[i].x,
                particles[i].y,
                particles[i].size * 1.3f
            );
        }

        glDisable(GL_BLEND);


        // Small birds

        for (int i = 0; i < BIRD_COUNT; i++)
        {
            drawBird(
                birds[i].x,
                birds[i].y,
                birds[i].size * 0.45f,
                birds[i].flap
            );
        }
    }


    // THEME 3 - SPACE WORLD

    else
    {
        // Dark galaxy gradient

        glBegin(GL_QUADS);

        glColor3f(
            0.005f,
            0.005f,
            0.025f
        );

        glVertex2f(0, 0);
        glVertex2f(WIDTH, 0);

        glColor3f(
            0.04f,
            0.015f,
            0.12f
        );

        glVertex2f(WIDTH, HEIGHT);
        glVertex2f(0, HEIGHT);

        glEnd();


        // Nebula glow

        glEnable(GL_BLEND);

        glBlendFunc(
            GL_SRC_ALPHA,
            GL_ONE_MINUS_SRC_ALPHA
        );

        glColor4f(
            0.30f,
            0.05f,
            0.55f,
            0.12f
        );

        drawCircle(
            160,
            600,
            150
        );

        glColor4f(
            0.05f,
            0.30f,
            0.75f,
            0.12f
        );

        drawCircle(
            430,
            400,
            170
        );

        glColor4f(
            0.55f,
            0.08f,
            0.35f,
            0.10f
        );

        drawCircle(
            300,
            700,
            130
        );

        glDisable(GL_BLEND);


        // Stars

        glEnable(GL_BLEND);

        glBlendFunc(
            GL_SRC_ALPHA,
            GL_ONE_MINUS_SRC_ALPHA
        );

        for (int i = 0; i < PARTICLE_COUNT; i++)
        {
            float twinkle =
                0.45f +
                0.50f *
                sin(particles[i].y * 0.08f);

            glColor4f(
                0.80f,
                0.90f,
                1.0f,
                twinkle
            );

            drawCircle(
                particles[i].x,
                particles[i].y,
                particles[i].size
            );
        }

        glDisable(GL_BLEND);


        // LARGE BLUE PLANET

        glColor3f(
            0.20f,
            0.32f,
            0.65f
        );

        drawCircle(
            475,
            620,
            55
        );

        glColor3f(
            0.35f,
            0.50f,
            0.85f
        );

        drawCircle(
            460,
            635,
            18
        );


        // Planet atmosphere

        glEnable(GL_BLEND);

        glBlendFunc(
            GL_SRC_ALPHA,
            GL_ONE_MINUS_SRC_ALPHA
        );

        glColor4f(
            0.30f,
            0.60f,
            1.0f,
            0.20f
        );

        drawCircle(
            475,
            620,
            70
        );

        glDisable(GL_BLEND);


        // SMALL RED PLANET

        glColor3f(
            0.75f,
            0.18f,
            0.12f
        );

        drawCircle(
            110,
            620,
            28
        );


        // Planet ring

        glColor3f(
            0.55f,
            0.65f,
            0.85f
        );

        glLineWidth(3.0f);

        glBegin(GL_LINE_LOOP);

        for (int i = 0; i < 80; i++)
        {
            float angle =
                2.0f *
                3.1415926f *
                i /
                80.0f;

            float x =
                110 +
                cos(angle) *
                45;

            float y =
                620 +
                sin(angle) *
                12;

            glVertex2f(x, y);
        }

        glEnd();

        glLineWidth(1.0f);


        // FLOATING ASTEROIDS

        glColor3f(
            0.30f,
            0.30f,
            0.38f
        );

        drawCircle(
            170,
            430,
            12
        );

        drawCircle(
            360,
            570,
            8
        );

        drawCircle(
            540,
            350,
            14
        );

        drawCircle(
            70,
            300,
            9
        );


        // Asteroid craters

        glColor3f(
            0.16f,
            0.16f,
            0.22f
        );

        drawCircle(
            167,
            434,
            3
        );

        drawCircle(
            363,
            572,
            2
        );

        drawCircle(
            537,
            354,
            4
        );


        // Small space creatures / birds

        for (int i = 0; i < BIRD_COUNT; i++)
        {
            drawBird(
                birds[i].x,
                birds[i].y,
                birds[i].size * 0.35f,
                birds[i].flap
            );
        }
    }
}


// UPDATE BACKGROUND

void updateBackground()
{
    // ID: ANIM-03, ANIM-04
    // Birds

    for (int i = 0; i < BIRD_COUNT; i++)
    {
        birds[i].x += birds[i].speed;

        birds[i].flap +=
            birds[i].flapSpeed;

        birds[i].y +=
            sin(birds[i].flap * 0.35f)
            * 0.12f;

        if (birds[i].x > WIDTH + 40)
        {
            birds[i].x = -40;

            birds[i].y =
                160 +
                rand() % 520;

            birds[i].size =
                0.60f +
                (rand() % 60) / 100.0f;
        }
    }


    // Particles

    for (int i = 0; i < PARTICLE_COUNT; i++)
    {
        particles[i].y -=
            particles[i].speed;

        particles[i].x +=
            sin(particles[i].y * 0.03f)
            * 0.15f;

        if (particles[i].y < 20)
        {
            particles[i].y =
                HEIGHT - 20;

            particles[i].x =
                20 +
                rand() %
                (WIDTH - 40);
        }
    }
}


// UPDATE PLATFORMS

void updatePlatforms()
{
    // ID: ANIM-02
    for (int i = 0;
         i < PLATFORM_COUNT;
         i++)
    {
        if (!platforms[i].moving)
            continue;

        platforms[i].x +=
            platforms[i].speed *
            platforms[i].direction;

        if (platforms[i].x >=
            platforms[i].maxX)
        {
            platforms[i].x =
                platforms[i].maxX;

            platforms[i].direction =
                -1;
        }

        if (platforms[i].x <=
            platforms[i].minX)
        {
            platforms[i].x =
                platforms[i].minX;

            platforms[i].direction =
                1;
        }
    }
}


// PLAYER

void drawPlayer()
{
    // ID: OBJ-01
    glColor3f(
        0.65f,
        0.12f,
        0.18f
    );

    drawRect(
        playerX + 3,
        playerY - 3,
        playerWidth,
        playerHeight
    );


    glColor3f(
        0.95f,
        0.25f,
        0.35f
    );

    drawRect(
        playerX,
        playerY,
        playerWidth,
        playerHeight
    );


    glColor3f(
        1.0f,
        0.40f,
        0.48f
    );

    drawRect(
        playerX + 5,
        playerY + 5,
        7,
        playerHeight - 10
    );


    // Eyes

    glColor3f(
        1.0f,
        1.0f,
        1.0f
    );

    drawCircle(
        playerX + 13,
        playerY + 38,
        6
    );

    drawCircle(
        playerX + 32,
        playerY + 38,
        6
    );


    glColor3f(
        0.0f,
        0.0f,
        0.0f
    );

    drawCircle(
        playerX + 13,
        playerY + 38,
        2.5f
    );

    drawCircle(
        playerX + 32,
        playerY + 38,
        2.5f
    );


    // Mouth

    glLineWidth(2.0f);

    glBegin(GL_LINES);

    glVertex2f(
        playerX + 15,
        playerY + 17
    );

    glVertex2f(
        playerX + 30,
        playerY + 17
    );

    glEnd();

    glLineWidth(1.0f);
}


// PLATFORMS

void drawPlatforms()
{
    // ID: OBJ-02
    for (int i = 0;
         i < PLATFORM_COUNT;
         i++)
    {
        // Shadow

        glColor3f(
            0.05f,
            0.38f,
            0.12f
        );

        drawRect(
            platforms[i].x,
            platforms[i].y - 2,
            platforms[i].width,
            platforms[i].height
        );


        // Platform

        glColor3f(
            0.10f,
            0.65f,
            0.20f
        );

        drawRect(
            platforms[i].x,
            platforms[i].y,
            platforms[i].width,
            platforms[i].height
        );


        // Top highlight

        glColor3f(
            0.30f,
            0.90f,
            0.35f
        );

        drawRect(
            platforms[i].x,
            platforms[i].y +
                platforms[i].height - 3,
            platforms[i].width,
            3
        );


        // Moving platform indicator

        if (platforms[i].moving)
        {
            glColor3f(
                0.55f,
                1.0f,
                0.55f
            );

            drawCircle(
                platforms[i].x +
                    platforms[i].width / 2.0f,

                platforms[i].y +
                    platforms[i].height + 3,

                2.0f
            );
        }
    }
}


// TEXT

void drawText(
    float x,
    float y,
    string text)
{
    // ID: OBJ-15
    glRasterPos2f(
        x,
        y
    );

    for (char c : text)
    {
        glutBitmapCharacter(
            GLUT_BITMAP_HELVETICA_18,
            c
        );
    }
}


// MOVEMENT

void updateMovement()
{
    // ID: ANIM-01
    velocityX = 0.0f;

    if (leftPressed)
    {
        velocityX =
            -moveSpeed;
    }

    if (rightPressed)
    {
        velocityX =
            moveSpeed;
    }

    playerX += velocityX;


    // Screen wrapping

    if (playerX < -playerWidth)
    {
        playerX = WIDTH;
    }

    if (playerX > WIDTH)
    {
        playerX = -playerWidth;
    }
}


// PLATFORM COLLISION

void checkPlatformCollision(
    float oldY)
{
    // ID: ANIM-01
    if (velocityY >= 0)
    {
        return;
    }

    float oldBottom =
        oldY;

    float newBottom =
        playerY;


    for (int i = 0;
         i < PLATFORM_COUNT;
         i++)
    {
        Platform &p =
            platforms[i];


        bool horizontalCollision =
            playerX + playerWidth > p.x &&
            playerX < p.x + p.width;


        bool verticalCollision =
            oldBottom >=
                p.y + p.height &&
            newBottom <=
                p.y + p.height;


        if (horizontalCollision &&
            verticalCollision)
        {
            playerY =
                p.y + p.height;

            velocityY =
                jumpPower;

            canJump = true;

            playJumpSound();


            if (i > highestPlatform)
            {
                highestPlatform =
                    i;

                score =
                    highestPlatform;
            }


            // Win after reaching platform 100

            if (i ==
                PLATFORM_COUNT - 1)
            {
                gameWon = true;
                gameOver = false;

                if (!winSoundPlayed)
                {
                    playWinSound();
                    winSoundPlayed = true;
                }
            }

            return;
        }
    }
}


// ============================================================
// CAMERA
// ============================================================

void updateCamera()
{
    // ID: ANIM-05
    float targetCamera =
        playerY - 300.0f;

    if (targetCamera > cameraY)
    {
        cameraY +=
            (targetCamera - cameraY)
            * 0.08f;
    }

    if (cameraY < 0)
    {
        cameraY = 0;
    }
}


// GAME UPDATE

void updateGame()
{
    // ID: ANIM-01, ANIM-07
    if (gameOver ||
        gameWon)
    {
        return;
    }


    updateMovement();

    updatePlatforms();


    float oldY =
        playerY;


    velocityY +=
        gravity;

    playerY +=
        velocityY;


    checkPlatformCollision(
        oldY
    );


    updateCamera();

    updateBackground();


    // Player fell too far below camera

    if (playerY + playerHeight <
        cameraY - 120)
    {
        gameOver = true;


        if (!gameOverSoundPlayed)
        {
            playGameOverSound();

            gameOverSoundPlayed = true;

            deathCount++;


            /* IMPORTANT:
            //
            // 0 = Sky
            // 1 = Volcanic
            // 2 = Frozen
            // 3 = Space
            //
             Repeats every 4 deaths.*/

            backgroundTheme =
                deathCount % 4;
        }
    }
}


// RESET GAME

void resetGame()
{
    // ID: ANIM-08
    playerX =
        277.5f;

    playerY =
        135.0f;

    velocityX =
        0.0f;

    velocityY =
        jumpPower;


    leftPressed =
        false;

    rightPressed =
        false;


    canJump =
        true;


    cameraY =
        0.0f;


    score =
        0;

    highestPlatform =
        0;


    gameOver =
        false;

    gameWon =
        false;


    gameOverSoundPlayed =
        false;

    winSoundPlayed =
        false;


    /* IMPORTANT:
     Do NOT reset deathCount or backgroundTheme.
     This allows the scenario to continue:
     Sky -> Volcanic -> Frozen -> Space -> Sky ...*/

    createPlatforms();
}


// GAME OVER SCREEN

void drawGameOver()
{
    // ID: OBJ-13
    glEnable(GL_BLEND);

    glBlendFunc(
        GL_SRC_ALPHA,
        GL_ONE_MINUS_SRC_ALPHA
    );

    glColor4f(
        0.0f,
        0.0f,
        0.0f,
        0.55f
    );


    glBegin(GL_QUADS);

    glVertex2f(0, 0);
    glVertex2f(WIDTH, 0);
    glVertex2f(WIDTH, HEIGHT);
    glVertex2f(0, HEIGHT);

    glEnd();

    glDisable(GL_BLEND);


    glColor3f(
        1.0f,
        1.0f,
        1.0f
    );


    drawText(
        210,
        450,
        "GAME OVER"
    );


    drawText(
        225,
        410,
        "Score: " +
        to_string(score)
    );


    drawText(
        190,
        370,
        "Press R to Restart"
    );
}


// WIN SCREEN

void drawWinScreen()
{
    // ID: OBJ-14
    glEnable(GL_BLEND);

    glBlendFunc(
        GL_SRC_ALPHA,
        GL_ONE_MINUS_SRC_ALPHA
    );

    glColor4f(
        0.0f,
        0.15f,
        0.05f,
        0.60f
    );


    glBegin(GL_QUADS);

    glVertex2f(0, 0);
    glVertex2f(WIDTH, 0);
    glVertex2f(WIDTH, HEIGHT);
    glVertex2f(0, HEIGHT);

    glEnd();

    glDisable(GL_BLEND);


    glColor3f(
        1.0f,
        1.0f,
        1.0f
    );


    drawText(
        190,
        470,
        "YOU WIN!"
    );


    drawText(
        205,
        425,
        "100 LEVELS"
    );


    drawText(
        210,
        385,
        "Score: 100"
    );


    drawText(
        175,
        340,
        "Press R to Play Again"
    );
}


// DISPLAY

void display()
{
    // ID: SUPPORT-04
    glClear(
        GL_COLOR_BUFFER_BIT
    );


    glMatrixMode(
        GL_MODELVIEW
    );

    glLoadIdentity();


    // Background stays fixed

    drawBackground();


    // World moves with camera

    glPushMatrix();

    glTranslatef(
        0.0f,
        -cameraY,
        0.0f
    );


    drawPlatforms();

    drawPlayer();


    glPopMatrix();


    // HUD

    glColor3f(
        0.0f,
        0.0f,
        0.0f
    );


    drawText(
        20,
        760,
        "Level: " +
        to_string(
            highestPlatform + 1
        )
    );


    drawText(
        20,
        730,
        "Score: " +
        to_string(score)
    );


    drawText(
        20,
        700,
        "A/D or <-/-> Move"
    );


    drawText(
        20,
        670,
        "UP = Jump"
    );


    if (gameOver)
    {
        drawGameOver();
    }


    if (gameWon)
    {
        drawWinScreen();
    }


    glutSwapBuffers();
}


// NORMAL KEYBOARD

void keyboard(
    unsigned char key,
    int x,
    int y)
{
    // ID: ANIM-06
    switch (key)
    {
        case 'a':
        case 'A':

            leftPressed =
                true;

            break;


        case 'd':
        case 'D':

            rightPressed =
                true;

            break;


        case 'r':
        case 'R':

            resetGame();

            break;


        case 'm':
        case 'M':

            soundOn =
                !soundOn;

            if (soundOn)
            {
                startBackgroundMusic();
            }
            else
            {
                stopBackgroundMusic();
            }

            break;


        case 27:

            stopBackgroundMusic();

            exit(0);

            break;
    }
}


// KEY RELEASE

void keyboardUp(
    unsigned char key,
    int x,
    int y)
{
    // ID: ANIM-06
    switch (key)
    {
        case 'a':
        case 'A':

            leftPressed =
                false;

            break;


        case 'd':
        case 'D':

            rightPressed =
                false;

            break;
    }
}


// SPECIAL KEYS

void specialKeyboard(
    int key,
    int x,
    int y)
{
    // ID: ANIM-06
    if (gameOver ||
        gameWon)
    {
        return;
    }


    if (key ==
        GLUT_KEY_LEFT)
    {
        playerX -=
            moveSpeed;
    }


    if (key ==
        GLUT_KEY_RIGHT)
    {
        playerX +=
            moveSpeed;
    }


    if (key ==
        GLUT_KEY_UP)
    {
        if (canJump)
        {
            velocityY =
                jumpPower;

            canJump =
                false;

            playJumpSound();
        }
    }


    // Screen wrapping

    if (playerX <
        -playerWidth)
    {
        playerX =
            WIDTH;
    }


    if (playerX >
        WIDTH)
    {
        playerX =
            -playerWidth;
    }


    glutPostRedisplay();
}


// TIMER

void timer(int value)
{
    // ID: ANIM-09
    updateGame();

    glutPostRedisplay();


    glutTimerFunc(
        16,
        timer,
        0
    );
}


// RESHAPE

void reshape(
    int w,
    int h)
{
    // ID: SUPPORT-05
    glViewport(
        0,
        0,
        w,
        h
    );


    glMatrixMode(
        GL_PROJECTION
    );

    glLoadIdentity();


    gluOrtho2D(
        0,
        WIDTH,
        0,
        HEIGHT
    );


    glMatrixMode(
        GL_MODELVIEW
    );
}


// OPENGL INITIALIZATION

void initGL()
{
    // ID: SUPPORT-06
    glClearColor(
        0.28f,
        0.58f,
        0.92f,
        1.0f
    );


    glPointSize(5.0f);


    createPlatforms();

    createParticles();


    canJump =
        true;


    startBackgroundMusic();
}


// MAIN

int main(
    int argc,
    char **argv)
{
    // ID: SUPPORT-07
    // Random seed

    srand(
        (unsigned int)
        time(NULL)
    );


    glutInit(
        &argc,
        argv
    );


    glutInitDisplayMode(
        GLUT_DOUBLE |
        GLUT_RGB
    );


    glutInitWindowSize(
        WIDTH,
        HEIGHT
    );


    glutInitWindowPosition(
        100,
        50
    );


    glutCreateWindow(
        "Doodle Jump - 100 Levels - Windows"
    );


    initGL();


    glutDisplayFunc(
        display
    );


    glutReshapeFunc(
        reshape
    );


    glutKeyboardFunc(
        keyboard
    );


    glutKeyboardUpFunc(
        keyboardUp
    );


    glutSpecialFunc(
        specialKeyboard
    );


    glutTimerFunc(
        16,
        timer,
        0
    );


    glutMainLoop();


    return 0;
}
