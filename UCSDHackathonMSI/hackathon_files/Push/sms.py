import email, smtplib, ssl
from providers import PROVIDERS

def send_sms_via_email(
        number:str,
        message:str,
        provider:str,
        sender_credentials:tuple,
        subject:str="Your Computer is Ready!",
        smtp_server="smtp.gmail.com",
        smtp_port:int=465
    ):
        sender_email, email_password = sender_credentials
        receiver_email = f'{number}@{PROVIDERS.get(provider).get("sms")}'

        email_message = f"Subject:{subject}\nTo:{receiver_email}\n{message}"

        with smtplib.SMTP_SSL(smtp_server, smtp_port, context=ssl.create_default_context()) as email:
                email.login(sender_email, email_password)
                email.sendmail(sender_email, receiver_email, email_message)


def main():
        number = 8582811388
        message = "head to TEC center to confirm your spot."
        provider = "T-Mobile"
        sender_credentials = ("aaron.ucsdhackathon@gmail.com", "voly lfck ozwe rbhj")

        send_sms_via_email(number, message, provider, sender_credentials)

if __name__ == "__main__":
        main()