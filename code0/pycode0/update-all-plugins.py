import pkg_resources
from subprocess import call
 
for packages in [dist.project_name for dist in pkg_resources.working_set]:
    call("pip3 install --upgrade " + ''.join(packages) + ' --user', shell=True)
