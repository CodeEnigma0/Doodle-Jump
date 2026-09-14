# Doodle-Jump

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
