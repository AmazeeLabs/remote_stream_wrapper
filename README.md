# Remote stream wrapper

A **fork** of [Remote stream wrapper](https://www.drupal.org/project/remote_stream_wrapper) Drupal module.

## Differences from original version

- [File Entity (fieldable files)](https://www.drupal.org/project/file_entity) is a dependency.
- User is able to change the file type.
- Internal paths are supported via `local://` scheme. They are treated as remote files.
- The filename_field (coming from the [Title](https://www.drupal.org/project/title) module) is supported
- Fixed mime detection.
