using AirporNameSpace;
Airport airport = new Airport();
airport.AddTariff("LA", 800);
airport.AddTariffWithDiscount("NY", 1000, 50);
Console.WriteLine($"max price: {airport.GetMaxPrice()}");