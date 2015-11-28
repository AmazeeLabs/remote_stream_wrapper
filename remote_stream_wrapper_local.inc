<?php

/**
 * Stream wrapper that allows use Drupal internal paths as remote files.
 */
class DrupalRemoteLocalStreamWrapper implements DrupalStreamWrapperInterface {

  /**
   * Remote wrapper we proxy.
   * 
   * @var DrupalRemoteStreamWrapper
   */
  protected $remoteStreamWrapper;

  /**
   * Constructor.
   */
  public function __construct() {
    $this->remoteStreamWrapper = new DrupalRemoteStreamWrapper();
  }

  /**
   * Converts Drupal internal path to absolute URL.
   *
   * @param string $local_uri
   *
   * @return string mixed
   */
  public static function localToRemote($local_uri) {
    $options = drupal_parse_url(substr($local_uri, 8));
    $path = $options['path'];
    unset($options['path']);
    $options['absolute'] = TRUE;
    return url($path, $options);
  }

  /**
   * {@inheritdoc}
   */
  public function stream_open($uri, $mode, $options, &$opened_url) {
    return $this->remoteStreamWrapper->stream_open(self::localToRemote($uri), $mode, $options, $opened_url);
  }

  /**
   * {@inheritdoc}
   */
  public function stream_close() {
    return $this->remoteStreamWrapper->stream_close();
  }

  /**
   * {@inheritdoc}
   */
  public function stream_lock($operation) {
    return $this->remoteStreamWrapper->stream_lock($operation);
  }

  /**
   * {@inheritdoc}
   */
  public function stream_read($count) {
    return $this->remoteStreamWrapper->stream_read($count);
  }

  /**
   * {@inheritdoc}
   */
  public function stream_write($data) {
    return $this->remoteStreamWrapper->stream_write($data);
  }

  /**
   * {@inheritdoc}
   */
  public function stream_eof() {
    return $this->remoteStreamWrapper->stream_eof();
  }

  /**
   * {@inheritdoc}
   */
  public function stream_seek($offset, $whence) {
    return $this->remoteStreamWrapper->stream_seek($offset, $whence);
  }

  /**
   * {@inheritdoc}
   */
  public function stream_flush() {
    return $this->remoteStreamWrapper->stream_flush();
  }

  /**
   * {@inheritdoc}
   */
  public function stream_tell() {
    return $this->remoteStreamWrapper->stream_tell();
  }

  /**
   * {@inheritdoc}
   */
  public function stream_stat() {
    return $this->remoteStreamWrapper->stream_stat();
  }

  /**
   * {@inheritdoc}
   */
  public function unlink($uri) {
    return $this->remoteStreamWrapper->unlink(self::localToRemote($uri));
  }

  /**
   * {@inheritdoc}
   */
  public function rename($from_uri, $to_uri) {
    return $this->remoteStreamWrapper->rename(self::localToRemote($from_uri), self::localToRemote($to_uri));
  }

  /**
   * {@inheritdoc}
   */
  public function mkdir($uri, $mode, $options) {
    return $this->remoteStreamWrapper->mkdir(self::localToRemote($uri), $mode, $options);
  }

  /**
   * {@inheritdoc}
   */
  public function rmdir($uri, $options) {
    return $this->remoteStreamWrapper->rmdir(self::localToRemote($uri), $options);
  }

  /**
   * {@inheritdoc}
   */
  public function url_stat($uri, $flags) {
    return $this->remoteStreamWrapper->url_stat(self::localToRemote($uri), $flags);
  }

  /**
   * {@inheritdoc}
   */
  public function dir_opendir($uri, $options) {
    return $this->remoteStreamWrapper->dir_opendir(self::localToRemote($uri), $options);
  }

  /**
   * {@inheritdoc}
   */
  public function dir_readdir() {
    return $this->remoteStreamWrapper->dir_readdir();
  }

  /**
   * {@inheritdoc}
   */
  public function dir_rewinddir() {
    return $this->remoteStreamWrapper->dir_rewinddir();
  }

  /**
   * {@inheritdoc}
   */
  public function dir_closedir() {
    return $this->remoteStreamWrapper->dir_closedir();
  }

  /**
   * {@inheritdoc}
   */
  function setUri($uri) {
    return $this->remoteStreamWrapper->setUri(self::localToRemote($uri));
  }

  /**
   * {@inheritdoc}
   */
  public function getUri() {
    return $this->remoteStreamWrapper->getUri();
  }

  /**
   * {@inheritdoc}
   */
  public function getExternalUrl() {
    return $this->remoteStreamWrapper->getExternalUrl();
  }

  /**
   * {@inheritdoc}
   */
  public static function getMimeType($uri, $mapping = NULL) {
    return DrupalRemoteStreamWrapper::getMimeType(self::localToRemote($uri), $mapping);
  }

  /**
   * {@inheritdoc}
   */
  public function chmod($mode) {
    return $this->remoteStreamWrapper->chmod($mode);
  }

  /**
   * {@inheritdoc}
   */
  public function realpath() {
    return $this->remoteStreamWrapper->realpath();
  }

  /**
   * {@inheritdoc}
   */
  public function dirname($uri = NULL) {
    return $this->remoteStreamWrapper->dirname(self::localToRemote($uri));
  }
}
