from ctypes import cdll, c_int, c_void_p
from pathlib import Path


class SandboxAPI:
    def __init__(self):
        api_lib = Path(__file__).parent.parent.parent / 'cmake-build-debug' / 'libstatelibrary.so'
        self.api = cdll.LoadLibrary(api_lib)
        self.api.getNewState.argtypes = []
        self.api.getNewState.restype = c_void_p
        self.api.clearState.argtypes = [c_void_p]
        self.api.clearState.restype = c_void_p
        self.api.deleteState.argtypes = [c_void_p]
        self.api.deleteState.restype = c_void_p
        self.api.runSimulation.argtypes = [c_void_p]
        self.api.runSimulation.restype = c_int

    def get_new_state(self) -> c_void_p:
        return self.api.getNewState()

    def clear_state(self, state: c_void_p) -> None:
        self.api.clearState(state)

    def delete_state(self, state: c_void_p) -> None:
        self.api.deleteState(state)

    def run_simulation(self, state: c_void_p) -> int:
        return self.api.runSimulation(state)
