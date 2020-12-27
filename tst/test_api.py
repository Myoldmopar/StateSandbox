from os import environ
from pathlib import Path
import sys

api_dir = Path(__file__).parent.parent.absolute() / 'src' / 'api'
sys.path.insert(0, str(api_dir))
from sandbox import SandboxAPI

if environ.get('CI', None):
    api_lib = Path(__file__).parent.parent / 'build' / 'libstatelibrary.so'
else:  # my local path, change as needed
    api_lib = Path(__file__).parent.parent / 'cmake-build-debug' / 'libstatelibrary.so'

a = SandboxAPI(api_lib)
s = a.get_new_state()
a.run_simulation(s)
a.clear_state(s)
a.run_simulation(s)
a.delete_state(s)
