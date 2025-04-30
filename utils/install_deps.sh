#!/bin/sh
sudo xbps-install nvidia xorg libX11-devel libXft-devel base-devel pavucontrol dmenu pipewire wireplumber libspa-bluetooth bluez Thunar firefox wezterm dbus elogind libXinerama-devel xterm picom xdg-user-dirs feh nerd-fonts alsa-pipewire xdotool
sudo ln -s /etc/sv/dbus/ /var/service/
sudo mkdir -p /etc/pipewire/pipewire.conf.d
sudo ln -s /usr/share/examples/wireplumber/10-wireplumber.conf /etc/pipewire/pipewire.conf.d/
sudo ln -s /usr/share/examples/pipewire/20-pipewire-pulse.conf /etc/pipewire/pipewire.conf.d/
sudo mkdir -p /etc/alsa/conf.d
sudo ln -s /usr/share/alsa/alsa.conf.d/50-pipewire.conf /etc/alsa/conf.d
sudo ln -s /usr/share/alsa/alsa.conf.d/99-pipewire-default.conf /etc/alsa/conf.d
