const long NO_INPUT{-2147483648};

long ler_inteiro_do_serial()
{
	delay(8);
	int num_bytes{Serial.available()};
	if (num_bytes > 1)
	{
		char buffer[64]{};
		size_t buff_counter{0};
		char temp{};
		bool number_started{false};
		bool space_in_between{false};
		--num_bytes;
		for (size_t i{0}; i < num_bytes; ++i)
		{
			temp = Serial.read();
			if (temp != ' ')
			{
				if (space_in_between)
				{
					Serial.println("Entrada com espaço entre palavras");
					while (++i < (num_bytes + 1))
					{
						Serial.read(); // cleaning the remaining characters that were left in the buffer
					}
					return NO_INPUT;
				}
				if (temp >= '0' && temp <= '9')
				{
					buffer[buff_counter++] = temp;
					number_started = true;
				}
				else
				{
					Serial.println("Entrada com caracteres que não são numeros");
					while (++i < (num_bytes + 1))
					{
						Serial.read(); // cleaning the remaining characters that were left in the buffer
					}
					return NO_INPUT;
				}
			}
			else
			{
				if (number_started)
				{
					space_in_between = true;
				}
			}
		}
		buffer[buff_counter] = '\0';
		Serial.read(); // cleanning the last character('\n') that were left in the buffer
		return atol(buffer);
	}
	else
	{
		if (num_bytes)
		{
			Serial.read();
		}
		return NO_INPUT;
	}
}



String ler_generico_do_serial()
{
	if (Serial.available()) 
	{
    	return Serial.readStringUntil('\n');
	}
	return String{""};
}
