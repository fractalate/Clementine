#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QSystemTrayIcon>

#include "ui_mainwindow.h"

class PlaylistManager;
class Playlist;
class PlaylistView;
class Player;
class Library;
class LibraryConfigDialog;
class RadioModel;
class Song;
class RadioItem;
class OSD;
class TrackSlider;
class EditTagDialog;
class MultiLoadingIndicator;
class SettingsDialog;
class About;
class AddStreamDialog;
class ShortcutsDialog;
class AlbumCoverManager;
class ShuffleRepeatWidget;

class QSortFilterProxyModel;
class SystemTrayIcon;

class QNetworkAccessManager;

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QNetworkAccessManager* network, QWidget *parent = 0);
  ~MainWindow();

  void SetHiddenInTray(bool hidden);

 protected:
  void resizeEvent(QResizeEvent* event);
  void closeEvent(QCloseEvent* event);

 private slots:
  void QueueFiles(const QList<QUrl>& urls);
  void FilePathChanged(const QString& path);

  void ReportError(const QString& message);
  void MediaStopped();
  void MediaPaused();
  void MediaPlaying();

  void PlaylistRightClick(const QPoint& global_pos, const QModelIndex& index);
  void PlaylistPlay();
  void PlaylistStopAfter();
  void EditTracks();

  void PlayIndex(const QModelIndex& index);
  void StopAfterCurrent();

  void LibraryDoubleClick(const QModelIndex& index);
  void ClearLibraryFilter();

  void VolumeWheelEvent(int delta);
  void TrayClicked(QSystemTrayIcon::ActivationReason reason);

  void UpdateTrackPosition();

  void RadioDoubleClick(const QModelIndex& index);
  void InsertRadioItem(RadioItem*);
  void ScrobblingEnabledChanged(bool value);
  void Love();

  void LibraryScanStarted();
  void LibraryScanFinished();

  void PlayerInitFinished();

  void HideShowTrayIcon();

  void AddMedia();
  void AddStream();
  void AddStreamAccepted();
  
  void NewPlaylist() ; 
  
  void CurrentTabChanged ( int ) ; 
  
  void CurrentPlaylistChanged( Playlist * pPlaylist ) ; 
  
  void InitPlaylists() ; 

 private:
  void SaveGeometry();

  void SetCurrentPlaylist(PlaylistView* current);

 private:
  static const int kStateVersion;
  static const char* kSettingsGroup;
  static const char* kMediaFilterSpec;

  Ui::MainWindow ui_;
  SystemTrayIcon* tray_icon_;
  OSD* osd_;
  TrackSlider* track_slider_;
  ShuffleRepeatWidget* shuffle_repeat_widget_;
  EditTagDialog* edit_tag_dialog_;
  MultiLoadingIndicator* multi_loading_indicator_;
  LibraryConfigDialog* library_config_dialog_;
  About* about_dialog_;

  RadioModel* radio_model_;
  QList<Playlist*> playlists_;
  Playlist* current_playlist_;
  PlaylistView* current_playlist_view_;

  Player* player_;
  Library* library_;

  SettingsDialog* settings_dialog_;
  AddStreamDialog* add_stream_dialog_;
  ShortcutsDialog* shortcuts_dialog_;
  AlbumCoverManager* cover_manager_;

  QMenu* playlist_menu_;
  QAction* playlist_play_pause_;
  QAction* playlist_stop_after_;
  QModelIndex playlist_menu_index_;

  QSortFilterProxyModel* library_sort_model_;

  QTimer* track_position_timer_;
  QSettings settings_;
  PlaylistManager * playlistManager_ ; 
  int next_playlist_number_;
};

#endif // MAINWINDOW_H
