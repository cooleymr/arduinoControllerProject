# pip install appscript
# Run ^ in terminal to install appscript

from appscript import app, k

outlook = app('Microsoft Outlook') #Chosen email app

msg = outlook.make(
    new=k.outgoing_message,
    with_properties={
        k.subject: 'Different Subect line',
        k.plain_text_content: 'Another Email body'})

msg.make(
    new=k.recipient,
    with_properties={
        k.email_address: {
            k.name: 'My Friends name',
            k.address: 'cooleym840@gmail.com'}})

msg.open()
msg.activate()