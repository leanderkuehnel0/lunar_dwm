#!/bin/bash

SCRIPT_DIR=$(dirname "$0")
TARGET_DIR="$HOME"

copy_config() {
    cp -r "$SCRIPT_DIR/dotfiles/.config" "$TARGET_DIR/"
}

copy_icons() {
    cp -r "$SCRIPT_DIR/dotfiles/.icons" "$TARGET_DIR/"
}

copy_themes() {
    cp -r "$SCRIPT_DIR/dotfiles/.themes" "$TARGET_DIR/"
}

case "$1" in
    config)
        copy_config
        ;;
    icons)
        copy_icons
        ;;
    themes)
        copy_themes
        ;;
    "")
        copy_config
        copy_icons
        copy_themes
        ;;
    *)
        echo "Usage: $0 [config|icons|themes]"
        exit 1
        ;;
esac

