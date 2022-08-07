# encoding: utf-8:
import json
import random
import time
import datetime
import aiohttp
# import traceback
# import requests

from datetime import datetime, timedelta

from khl import Bot, Message, EventTypes, Event,Client,MessageTypes
from khl.card import CardMessage, Card, Module, Element, Types, Struct
from khl.command import Rule
# import khl.task
# from khl.guild import Guild,GuildUser


# 新建机器人，token 就是机器人的身份凭证
# 用 json 读取 config.json，装载到 config 里
# 注意文件路径，要是提示找不到文件的话，就 cd 一下工作目录/改一下这里
with open('./config/config.json', 'r', encoding='utf-8') as f:
    config = json.load(f)
# 用读取来的 config 初始化 bot，字段对应即可
bot = Bot(token=config['token'])

Botoken=config['token']
kook="https://www.kookapp.cn"
headers={f'Authorization': f"Bot {Botoken}"}

######################################################################################

def GetTime(): #将获取当前时间封装成函数方便使用
    return time.strftime("%y-%m-%d %H:%M:%S", time.localtime())

# 开机的时候打印一次时间，记录重启时间
print(f"Start at: [%s]"%GetTime())

# 在控制台打印msg内容，用作日志
def logging(msg: Message):
    now_time = GetTime()
    print(f"[{now_time}] G:{msg.ctx.guild.id} - C:{msg.ctx.channel.id} - Au:{msg.author_id}_{msg.author.username}#{msg.author.identify_num} = {msg.content}")


@bot.command()
async def hello(msg:Message):
    logging(msg)
    await msg.reply("world!")

@bot.command(name='OJhelp')
async def help(msg:Message):
    logging(msg)
    await msg.reply(f"打卡方式：`/打卡 01 leetcode105`\n可同时打卡多道题目：`/打卡 01 leetcode105 牛客jz45`")

# 正则不会匹配图片
# @bot.command(regex=r'(.+)')
# async def TL_Realtime(msg:Message,*arg):
#     logging(msg)


# oj刷题信息
OjDict = {
    'user': '', 
    'name':'',
    'day': '', 
    'date':'',
    'oj':[]
}

def GetDate(): #将获取当前日期成函数方便使用
    return time.strftime("%y-%m-%d", time.localtime())

# 打卡
@bot.command(name='打卡',aliases=['OJ'])
#async def oj_hander(msg:Message,today:str ='err',oj_name:str='err',trash:str='err'): #这里故意添加第4个参数，以防打错 
async def oj_hander(msg:Message,today:str ='err',*arg):
    logging(msg)
    #print(arg)
    if today == 'err' or arg==():
        await msg.reply(f"打卡参数错误！day: `{today}` oj:`{arg}`")
        return
    elif len(today)!=2:
        await msg.reply(f"打卡天数错误！day: `{today}`\n打卡天数仅支持两位数，如: 01,23")
        return

    try:
        global  OjDict
        OjDict['user']=msg.author_id
        OjDict['name']=msg.author.nickname
        OjDict['day']=today
        OjDict['date']= GetDate()
        OjDict['oj']=arg

        flag = 0
        with open("./log/oj.json",'r',encoding='utf-8') as fr1:
            data = json.load(fr1)
        for s in data:
            if s['user'] == msg.author_id:
                date = GetDate()
                # 支持正常追加当天打卡天数
                if s['date'] == date and today == s['day']:
                    s['day'] = today
                    s['date'] = date
                    for i in arg:
                        s['oj'].append(i) #如果该用户之前已经打过卡，则在后面追加内容
                    flag =1
                    break
                elif s['date'] == date and today != s['day']:
                    await msg.reply(f"今天是你打卡的第{s['day']}天，你已经打过卡辣！可以用`/打卡 {s['day']} 题号`来追加当日打卡题目，但不可以改变打卡天数哦~")
                    return

        if flag ==1:
            await msg.reply(f"打卡成功！这是你打卡的第{today}天")
        else:
            data.append(OjDict)
            await msg.reply(f"首天打卡成功！这是你打卡的第01天")

        #不管是否已存在，都需要重新执行写入（更新/添加）
        with open("./log/oj.json",'w',encoding='utf-8') as fw1:
            json.dump(data,fw1,indent=2,sort_keys=True, ensure_ascii=False)        
        fw1.close()

    except Exception as result:
        cm2 = CardMessage()
        c = Card(Module.Header(f"很抱歉，发生了一些错误"), Module.Context(f"请检查您提供的参数是否正确"))
        c.append(Module.Divider())
        c.append(Module.Section(f"【报错】  {result}\n"))
        c.append(Module.Divider())
        c.append(Module.Context('有任何问题，请联系(met)1961572535(met}',Types.Text.KMD))
        cm2.append(c)
        await msg.reply(cm2)

# 收集打卡截图
PicDict={
    'user': '', 
    'name':'',
    'png':[]
}

# 处理图片消息
async def image_handler(msg:Message):
    logging(msg)
    #print(msg.content)
    if msg.ctx.channel.id == '3822310432593316':
        global  PicDict
        PicDict['user']=msg.author_id
        PicDict['name']=msg.author.nickname
        PicDict['png']=[msg.content]

        flag = 0
        with open("./log/pic.json",'r',encoding='utf-8') as fr1:
            data = json.load(fr1)
        for p in data:
            if p['user'] == msg.author_id:
                date = GetDate()
                p['png'].append(msg.content) #如果该用户之前已经打过卡，则在后面追加截图
                flag = 1
                break
        
        if flag == 0:
            data.append(PicDict)
               
        #不管是否已存在，都需要重新执行写入（更新/添加）
        with open("./log/pic.json",'w',encoding='utf-8') as fw1:
            json.dump(data,fw1,indent=2,sort_keys=True, ensure_ascii=False)        
        fw1.close()



# 回调函数来处理图片消息
bot.client.register(MessageTypes.IMG, image_handler)


bot.run()