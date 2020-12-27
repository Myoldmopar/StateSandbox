import pathlib
import sys

api_dir = pathlib.Path(__file__).parent.parent.absolute() / 'src' / 'api'
sys.path.insert(0, str(api_dir))
from sandbox import SandboxAPI

a = SandboxAPI()
s = a.get_new_state()
a.run_simulation(s)
a.clear_state(s)
a.run_simulation(s)
a.delete_state(s)
