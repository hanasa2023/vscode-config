import botpy
from botpy.message import Message

class MyBot(botpy.Client):
    async def on_at_message_create(self, message: Message):
        await message.reply(content=f"{self.robot.name}, {self.robot.avatar}, {self.robot.id}, {message.content}")

if __name__ == "__main__":
    intents = botpy.Intents(public_guild_messages=True)
    client = MyBot(intents=intents)
    client.run(appid='102072922', token='3MuKg44sDPeR6cys0MiH83wxwz0QJ5Uh')