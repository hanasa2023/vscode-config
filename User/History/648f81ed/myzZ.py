import botpy
from botpy.message import Message

class MyBot(botpy.Client):
    async def on_at_message_create(self, message: Message):
        await message.reply(f"{self.robot.name}, {self.robot.avatar}, {self.robot.id}, {message.content}")

intents = botpy.Intents(public_guild_messages=True)
client = MyBot(intents=intents)