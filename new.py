import sys
import json
from pygame.locals import *

sys.path.insert(0,'/home/ubuntu/Desktop')
class GymController(object):
	def __init__(self):
		self.LastKey = 3
		self.NumberGames = 3
		self.a = 0
		self.counter = 0
		self.Steps = 0
		self.total_reward = 0
		self.interval_of_time = 0
		self.count = 0
		self.output = ""
		self.data_ram = dict()
		self.data_rgb = dict()
		self.Actions = []
		self.transpose = True
		self.game = Game()
		self.sg = ScreenGame()
		self.game.Enviroment()
		self.agent = RandomAgent(self.game)
	def SetNumberGames(self, numbergames):
		self.NumberGames = numbergames
	def GetNumberGames(self):
		return self.NumberGames

	def getObservations(self):
		import sys
		self.output = {"Observation" : self.data_ram,"Reward" : self.total_reward,"Steps" : self.Steps,"Actions" : self.Actions,"NameGame" : self.game.GetNameGame() }
		output_string = json.dumps(self.output)
		sys.stdout.write(output_string)
	def Execute(self):
		import pygame
		greater_reward = 0
		lastKey = self.LastKey
		while self.counter < self.GetNumberGames():
			while self.game.GetDone() != True:
				#ram, puntaje del juego, estado del juego, ndarray de rgbs
				obs, reward, vardone, rgb_array = self.game.GetEnviroment().step(lastKey)
				#seteamos el estado del juego obtenido sea true o false
				self.game.SetDone(vardone)
				#almacenamos el puntaje total obtenido hasta el momento jugando
				self.total_reward += reward 
				#contamos cuantos pasos se esta dando
				self.Steps += 1 
				#almacenamos en una lista  la ram
				self.data_ram[self.Steps] = obs.tolist()
				#almacenamos en un array la ultima accion(movimiento) del juego
				self.Actions.append(lastKey)
				#generamos un nuevo movimiento a partir del tipo de agente que tengamos
				keyGen = self.agent.Generate(lastKey)
				#si mi movimiento es vacio asigno mi ultimo movimeinot
				if keyGen != None:
					lastKey = keyGen
				if obs is not None:
					#del rgb obtenido mediante pygame haremos la visualizacion del estado acutal
					self.sg.display_arr(rgb_array, self.transpose)
				pygame.display.flip()
				#obtenemos el clock del pygame
				clock = self.sg.GetClock()
				#seteamos los frames
				clock.tick(self.sg.GetVelocity())
			#aqui volvemos re resetear los datos del juego si es que ya perdio
			vardone = False
			self.game.SetDone(vardone)
			#almacenamos el puntaje del juego
			if greater_reward < self.total_reward:
				greater_reward = self.total_reward
			self.total_reward = 0
			self.counter += 1
			#reseteamos el ambiente
			self.game.ResetEnviroment()
		#tenemos el puntaje total de los juegos realizados
		self.total_reward = greater_reward
		#cerramos pygame
		pygame.quit()

class RandomAgent(object):
		def __init__(self, game):
			self.interval_of_time = 0
			self.frames_by_decision = 10
			self.interval_deny_last_key = 5
			self.count2 = 0
			self.count = 0
			self.deny_key = 0
			self.i = Interval()
			self.kc = KeyCombination()
			self.kg = KeyGenerator()
			self.kg.ActionKey(game)
		def SetIntervalTime(self, intervaltime):
			self.interval_of_time = intervaltime
		def SetFramesByDecision(self, FramesByDecision):
			self.frames_by_decision = FramesByDecision
		def SetIntervalDenyLastKey(self, intervalDenyLastKey):
			self.interval_deny_last_key = intervalDenyLastKey
		def GetIntervalTime(self):
			return self.interval_of_time

		def GetFramesByDecision(self):
			return self.frames_by_decision

		def GetIntervalDenyLastKey(self):
			return self.interval_deny_last_key

		def Generate(self, lastkey):
			self.count += 1 
			if self.count > self.GetFramesByDecision():
				self.count = 0
				gen = self.Generate_by_intervals()
				self.count2 += 1 
				if self.count2 < self.GetIntervalDenyLastKey():
					while self.deny_key == gen:
						gen = self.Generate_by_intervals()
				else:
					self.count2 = 0
					self.deny_key = self.kg.Inverse(lastkey)
				return gen

			return lastkey

		def Generate_by_intervals(self):
			import random
			
			if self.GetIntervalTime() <= self.i.GetInterval1():
					intime = (self.GetIntervalTime()+1)
					self.SetIntervalTime(intime)
					return random.choice(self.kg.GetArrayNumberKeys())

			if self.GetIntervalTime() > self.i.GetInterval1() and self.GetIntervalTime() <= self.i.GetInterval2():
					intime = (self.GetIntervalTime()+1)
					self.SetIntervalTime(intime)
					return random.choice(self.kc.GetKey2())

			if self.GetIntervalTime() >= self.i.GetInterval2():
					intime = (self.GetIntervalTime()+1)
					self.SetIntervalTime(intime)
					return random.choice(self.kc.GetKey1())

class Interval(object):
		def __init__(self):
			self.interval1 = 2
			self.interval2 = 1
		
		def SetInterval1(self, interval):
				self.interval1 = interval
		def SetInterval2(self, interval):
				self.interval2 = interval
		
		def GetInterval1(self):
				return self.interval1

		def GetInterval2(self):
				return self.interval2

class KeyGenerator(object):
		def __init__(self):
			self.Lastkey = 0
			self.NumberKeys = 0
			self.ArrayNumberKeys = []
		def SetLastKey(self, LastKey):
			self.LastKey = LastKey
		def SetNumberKeys(self, numberkeys):
			self.NumberKeys = numberkeys
		def GetLastKey(self):
			return self.LastKey

		def GetArrayNumberKeys(self):
			return self.ArrayNumberKeys

		def Inverse(self, key):
			if key == 0:
				return 1

			if key == 1:
				return 0

			if key == 2:
				return 5

			if key == 3:
				return 4

			if key == 4:
				return 3

			if key == 5:
				return 2

			if key == 6:
				return 7

			if key == 7:
				return 6

			if key == 8:
				return 9

			if key == 9:
				return 8

			if key == 10:
				return 13

			if key == 11:
				return 12

			if key == 12:
				return 11

			if key == 13:
				return 10

			if key == 14:
				return 15

			if key == 15:
				return 14

			if key == 16:
				return 17

			if key == 17:
				return 16

		def ActionKey(self, env):
			self.SetNumberKeys(env.GetEnviromentActionSpace())
			for x in range(0, self.NumberKeys) :
				self.ArrayNumberKeys.append(x)
class KeyCombination(object):
		def __init__(self):
			self.key1 = [2,3,5,4,4,4]
			self.key2 = [3,3,5,2,4]
		
		def SetKey1(self, kc):
				self.key1 = kc
		def SetKey2(self, kc):
				self.key2 = kc
		
		def GetKey1(self):
				return self.key1

		def GetKey2(self):
				return self.key2


class Game(object):
		def __init__(self):
			self.velocity = 0
			self.name_game = "MsPacman-ram-v0"
			self.done = False
			self.env = 0
			self.EnvActionSpace = 0
		def SetVelocity(self, velocity):
			self.velocity = velocity
		def SetNameGame(self, namegame):
			self.name_game = namegame
		def SetEnviroment(self, envi):
			self.env = envi
		def GetVelocity(self):
			return self.velocity

		def SetDone(self, done):
			self.done = done
		def GetDone(self):
			return self.done

		def GetNameGame(self):
			return self.name_game

		def Enviroment(self):
			
			import pygame
			import gym
			self.SetEnviroment(gym.make(self.GetNameGame()))
			self.EnviromentActionSpace()
			self.ResetEnviroment()
			pygame.display.set_caption(u'DEVINT-25 GAMES - Random')
		def EnviromentActionSpace(self):
			self.EnvActionSpace = self.env.action_space.n
		def GetEnviromentActionSpace(self):
			return self.EnvActionSpace

		def GetEnviroment(self):
			return self.env

		def ResetEnviroment(self):
			self.env.reset()
class ScreenGame(object):
		def __init__(self):
			import pygame
			self.videoSize = (400,400)
			self.velocity = 25
			self.clock = pygame.time.Clock()
			self.screen = pygame.display.set_mode(self.GetVideosize())
		def SetVideosize(self, videosize):
			self.videoSize = videosize

		def SetVelocity(self, velocity):
			self.velocity = velocity

		def SetClock(self, clockthings):
			self.clock = clockthings

		def SetScreen(self, screenthings):
			self.screen = screenthings

		def GetVideosize(self):
			return self.videoSize

		def GetVelocity(self):
			return self.velocity

		def GetClock(self):
			return self.clock

		def GetScreen(self):
			return self.screen

		def GraphicsConfig(self, Velocity, WindowSize):
			import pygame
			self.SetVideosize(WindowSize)
			self.SetVideosize(WindowSize)
			self.SetVelocity(Velocity)
			self.SetClock(pygame.time.Clock())
			self.SetScreen(pygame.display.set_mode(self.GetVideosize()))
		def display_arr(self, arr, transpose):
			import pygame
			arr_min, arr_max = arr.min(), arr.max()
			arr = 255.0 * (arr - arr_min) / (arr_max - arr_min)
			pyg_img = pygame.surfarray.make_surface(arr.swapaxes(0, 1) if transpose else arr)
			pyg_img = pygame.transform.scale(pyg_img, self.videoSize)
			self.screen.blit(pyg_img, (0,0))
if __name__ == "__main__":
	GC = GymController()
	GC.Execute()
