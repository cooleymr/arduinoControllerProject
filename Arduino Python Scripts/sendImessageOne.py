#Need to have sendMessage.applescript in the same directory as this file

from imessage_reader import fetch_data
import os

RECIPIENT_NUMBER = "+8478404037" # I suggest adding yours initially to test
MESSAGE = "'Whats up doc'"

fd = fetch_data.FetchData()
messages  = fd.get_messages()
os.system("osascript sendMessage.applescript {} {}".format(RECIPIENT_NUMBER, MESSAGE))