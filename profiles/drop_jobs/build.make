api = 2
core = 7.x

includes[core] = drupal-org-core.make

; Recursion will handle the rest of the build.
projects[drop_jobs][type] = profile
projects[drop_jobs][download][type] = git
projects[drop_jobs][download][url] = git://git.drupalcode.org/project/drop_jobs.git
projects[drop_jobs][download][branch] = 7.x-1.x
