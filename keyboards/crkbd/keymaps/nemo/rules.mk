#CONSOLE_ENABLE = yes
#COMMAND_ENABLE = yes
#DEBUG = yes
EXTRAKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
CFLAGS += -flto
BACKLIGHT_ENABLE = no     # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.
RGB_MATRIX_ENABLE = WS2812
MIDI_ENABLE = yes            # MIDI support (+2400 to 4200, depending on config)

#BOOTLOADER = caterina

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/glcdfont.c \
        ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \
