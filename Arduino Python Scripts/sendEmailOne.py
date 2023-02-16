# pip install appscript
# Run ^ in terminal to install appscript

from appscript import app, k

outlook = app('Microsoft Outlook') #Chosen email app

msg = outlook.make(
    new=k.outgoing_message,
    with_properties={
        k.subject: 'Subect line',
        k.plain_text_content: 'Email body'})

msg.make(
    new=k.recipient,
    with_properties={
        k.email_address: {
            k.name: 'Mr Boss Man',
            k.address: 'mrcooley@iu.edu'}})

msg.open()
msg.activate()